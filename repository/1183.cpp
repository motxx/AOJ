#include <assert.h>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
bool operator<(const P &a, const P &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}
double cross(const P &a, const P &b) { return imag(conj(a) * b); }
double dot(const P &a, const P &b) { return real(conj(a) * b); }

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a);
    push_back(b);
  }
  L(pair<P, P> pp) {
    push_back(pp.first);
    push_back(pp.second);
  }
};

struct C {
  P p;
  double r;
  C(const P &p, double r) : p(p), r(r) {}
};

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return +1;    // counter clockwise
  if (cross(b, c) < 0) return -1;    // clockwise
  if (dot(b, c) < 0) return +2;      // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;
}

bool intersectLL(const L &l, const L &m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||  // non-parallel
         abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;    // same line
}
bool intersectLS(const L &l, const L &s) {
  return cross(l[1] - l[0], s[0] - l[0]) *  // s[0] is left of l
             cross(l[1] - l[0], s[1] - l[0]) <
         EPS;  // s[1] is right of l
}
bool intersectLP(const L &l, const P &p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
bool intersectSP(const L &s, const P &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) <
         EPS;  // triangle inequality
}

P projection(const L &l, const P &p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

double distanceLP(const L &l, const P &p) { return abs(p - projection(l, p)); }
double distanceLL(const L &l, const L &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
double distanceLS(const L &l, const L &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
double distanceSS(const L &s, const L &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
P crosspoint(const L &l, const L &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

pair<P, P> circle_circle_intersect(C c1, C c2) {
  if (c1.p.real() > c2.p.real()) swap(c1, c2);
  const double d = abs(c2.p - c1.p);
  const double alpha = acos((c2.p.real() - c1.p.real()) / d) *
                       ((c1.p.imag() > c2.p.imag()) ? -1.0 : 1.0);
  const double beta =
      acos((c1.r * c1.r - c2.r * c2.r + d * d) / 2.0 / d / c1.r);
  return make_pair(c1.p + polar(c1.r, alpha - beta),
                   c1.p + polar(c1.r, alpha + beta));
}

struct Edge {
  int to;
  double cost;
};

vector<Edge> G[300];

map<P, int> mp;
int nidx;
void init_node_map(P ps, P pt, int N) {
  mp.clear();
  mp[ps] = 0;
  mp[pt] = (N - 1) * 2 + 1;
  nidx = 1;
}

int get_node(P p) {
  if (mp.find(p) == mp.end()) {
    mp[p] = nidx++;
  }
  return mp[p];
}

#define MAX (300)
double dist[MAX];

typedef pair<double, int> Pdi;

double dijkstra(int S, int T) {
  priority_queue<Pdi, vector<Pdi>, greater<Pdi> > PQ;
  fill(dist, dist + MAX, INF);
  dist[S] = 0;
  PQ.push(Pdi(0., S));

  while (!PQ.empty()) {
    Pdi pdi = PQ.top();
    PQ.pop();
    const int u = pdi.second;
    for (int i = 0; i < (int)G[u].size(); i++) {
      const Edge &e = G[u][i];
      if (dist[e.to] > dist[u] + e.cost) {
        dist[e.to] = dist[u] + e.cost;
        PQ.push(Pdi(dist[e.to], e.to));
      }
    }
  }

  return dist[T];
}

#define IINF2 (INT_MAX / 2)

int main() {
  int N;
  while (cin >> N && N) {
    for (int i = 0; i < 300; i++) G[i].clear();

    vector<C> cs;
    for (int i = 0; i < N; i++) {
      double x, y, r;
      cin >> x >> y >> r;
      cs.push_back(C(P(x, y), r));
    }

    vector<pair<P, P> > ips(N + 1);
    ips[0].first = cs[0].p;  // ips[0].second = P(-IINF2, -IINF2);
    for (int i = 0; i < N - 1; i++) {
      ips[i + 1] = circle_circle_intersect(cs[i], cs[i + 1]);
    }
    ips[N].first = cs[N - 1].p;  // ips.back().second = P(+IINF2, +IINF2);

    init_node_map(ips[0].first, ips[N].first, N);

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N + 1; j++) {
        const int dij = j - i;

        for (int k = 0; k < 2; k++) {
          if (i == 0 && k == 1) continue;

          const P pti = k == 0 ? ips[i].first : ips[i].second;
          const int a = get_node(pti);

          for (int l = 0; l < 2; l++) {
            if (j == N && l == 1) continue;

            const P ptj = l == 0 ? ips[j].first : ips[j].second;
            const int b = get_node(ptj);

            bool ok = true;
            const L sa(pti, ptj);
            // ?¶???????????????°?????????????£?
            for (int didx = 1; didx < dij; didx++) {
              const L sb(ips[i + didx]);
              ok = ok && intersectSS(sa, sb);
            }

            if (ok) {
              const double len = abs(pti - ptj);
              G[a].push_back((Edge){b, len});
              G[b].push_back((Edge){a, len});
            }
          }
        }
      }
    }

    printf("%.6f\n", dijkstra(get_node(cs[0].p), get_node(cs[N - 1].p)));
  }

  return 0;
}