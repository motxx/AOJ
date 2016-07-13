#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a)                                                               \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2> inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2> inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

struct xor128 {
  unsigned x, y, z, w;
  xor128() : x(random_device()()), y(157892372), z(7777777), w(757328) {}
  unsigned next() {
    unsigned t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = w ^ (w >> 19) ^ t ^ (t >> 8);
  }
  unsigned next(unsigned k) { return next() % k; }
} rndgen;

typedef complex<double> P;

namespace std {

bool operator<(P const &l, P const &r) {
  return abs(l.real() - r.real()) < 1e-5 ? l.imag() < r.imag()
                                         : l.real() < r.real();
}
}

namespace point_2d {

using Real = double;

Real const EPS = 1e-5; // !!! DO CHECK EPS !!!

// bool operator < (P const& l, P const& r) {  return abs(l.real() - r.real()) <
// EPS ? l.imag() < r.imag() : l.real() < r.real();}

bool operator>(P const &l, P const &r) {
  return abs(l.real() - r.real()) < EPS ? l.imag() > r.imag()
                                        : l.real() > r.real();
}

bool equals(Real a, Real b) { return abs(a - b) < EPS; }

bool equals(P const &l, P const &r) { return abs(l - r) < EPS; }

struct Line : public pair<P, P> {
  Line(P const &a, P const &b) { first = a, second = b; }
  const P &operator[](int x) const { return x == 0 ? first : second; }
  P &operator[](int x) { return x == 0 ? first : second; }
};
typedef Line Segment;

bool operator<(const Line &a, const Line &b) {
  return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
}

struct Circle {
  P p;
  Real r;
  Circle() {}
  Circle(P const &p, Real r) : r(r) { this->p = p; }
};

struct Polygon : public vector<P> {
  vector<P> &g = *this;
  Polygon() = default;
  Polygon(vector<P> const &g) { this->g = g; }
  P &operator[](int x) { return vector<P>::operator[]((x + size()) % size()); }
  Segment side(int x) {
    return std::move(Segment(this->operator[](x), this->operator[](x + 1)));
  }
  Segment backside(int x) {
    return std::move(Segment(this->operator[](x), this->operator[](x - 1)));
  }
};

Real cross(P const &a, P const &b) { return imag(conj(a) * b); }
Real dot(P const &a, P const &b) { return real(conj(a) * b); }
Real cos(P const &l, P const &r) {
  return dot(l, r) / (abs(l) * abs(r));
} // not verified

enum ccw_result {
  counter_clockwise = +1,
  clockwise = -1,
  online_back = +2,
  online_front = -2,
  on_segment = 0
};

ccw_result ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > 0) {
    return ccw_result::counter_clockwise;
  }
  if (cross(b, c) < 0) {
    return ccw_result::clockwise;
  }
  if (dot(b, c) < 0) {
    return ccw_result::online_back;
  }
  if (norm(b) < norm(c)) {
    return ccw_result::online_front;
  }
  return ccw_result::on_segment;
}

bool intersect_lp(Line const &l, P const &p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

bool intersect_sp(Line const &s, P const &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) <
         EPS; // triangle inequality
}

bool intersect_ss(Segment const &s, Segment const &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= EPS &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= EPS;
}

bool intersect_ll(Line const &l, Line const &m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || // non-parallel
         abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;   // same line
}

bool intersect_ls(Line const &l, Segment const &s) {
  return cross(l[1] - l[0], s[0] - l[0]) * // s[0] is left of l
             cross(l[1] - l[0], s[1] - l[0]) <
         EPS; // s[1] is right of l
}

P projection(Line const &l, P const &p) {
  auto t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

P reflection(Line const &l, P const &p) {
  return p + (Real)2.0 * (projection(l, p) - p);
}

Real distance_sp(Line const &s, P const &p) {
  P const r = projection(s, p);
  if (intersect_sp(s, r))
    return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

Real distance_lp(Line const &l, P const &p) {
  return abs(p - projection(l, p));
}

bool intersect_cl(Circle const &c, Line const &l) {
  return distance_lp(l, c.p) <= c.r + EPS;
}

bool intersect_cs(Circle const &c, Line const &l) {
  if (abs(l[0] - c.p) < c.r - EPS && abs(l[1] - c.p) < c.r - EPS) {
    return false;
  }
  return distance_lp(l, c.p) <= c.r + EPS;
}

bool intersect_gs(Polygon const &g, Segment const &s) { // not verified
  auto u = const_cast<Polygon &>(g);
  rep(i, g.size()) {
    if (!intersect_sp(s, u[i]) && intersect_ss(s, u.side(i))) {
      return true;
    }
  }
  return false;
}

P crosspoint(const Line &l, const Line &m) {
  auto A = cross(l[1] - l[0], m[1] - m[0]);
  auto B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS)
    return m[0]; // same line
  if (abs(A) < EPS)
    assert(false && "PRECONDITION NOT SATISFIED");
  return m[0] + B / A * (m[1] - m[0]);
}

pair<P, P> crosspoint(Circle const &c, Line const &l) {
  auto h = projection(l, c.p);
  auto e = (l[1] - l[0]) / abs(l[1] - l[0]);
  auto base = sqrt(c.r * c.r - abs(h - c.p) * abs(h - c.p));
  return {h + e * base, h - e * base};
}

pair<P, P> crosspoint(Circle c1, Circle c2) {
  if (c1.p.real() > c2.p.real())
    swap(c1, c2);
  auto const d = abs(c2.p - c1.p);
  auto const alpha = acos((c2.p.real() - c1.p.real()) / d) *
                     ((c1.p.imag() > c2.p.imag()) ? -1.0 : 1.0);
  auto const beta = acos((c1.r * c1.r - c2.r * c2.r + d * d) / 2.0 / d / c1.r);
  return make_pair(c1.p + polar(c1.r, alpha - beta),
                   c1.p + polar(c1.r, alpha + beta));
}

vector<P> tangent_points(Circle const &c, P const &p) {
  vector<P> ret;
  auto const sec2 = norm(p - c.p);
  auto const tan2 = max(Real(0), sec2 - c.r * c.r);
  auto const nv = (p - c.p) * c.r * c.r / sec2;
  auto const pv = (p - c.p) * P(0, -1) * c.r * sqrt(tan2) / sec2;
  ret.push_back(c.p + nv + pv);
  ret.push_back(c.p + nv - pv);
  return ret;
}

// 通常clangであれば、"(x, y)"の形式を読み取るが、これを"x y"に変更する
istream &operator>>(istream &is, P &p) {
  Real x, y;
  is >> x >> y;
  p = P(x, y);
  return is;
}
ostream &operator<<(ostream &os, Line const &l) {
  return os << "{" << l[0] << ", " << l[1] << "}";
}
}
using namespace point_2d;

namespace visualizer {

ofstream ofs;
constexpr double scale = 1;
constexpr double offset = 50;

void init() { ofs = ofstream("data.js"); }

void polygon(Polygon &g) {
  ofs << "polygon_start" << g[0] << endl;
  REP(i, 1, g.size()) { ofs << "lineTo" << g[i] << endl; }
  ofs << "polygon_end()" << endl;
}

void line(Line &l) {
  ofs << "line(" << l[0].real() * scale + offset << ","
      << l[0].imag() * scale + offset << ","
      << l[1].real() * scale + offset /*+ rndgen.next(5)*/ << ","
      << l[1].imag() * scale + offset /* + rndgen.next(5)*/
      << ",'rgb(" << rndgen.next(256) << "," << rndgen.next(256) << ","
      << rndgen.next(256) << ")')" << endl;
}

void point(P const &p) {
  ofs << "circle(" << p.real() * scale + offset << ","
      << p.imag() * scale + offset << ",10)" << endl;
}

void check(P const &p) {
  ofs << "circle(" << p.real() * scale + offset << ","
      << p.imag() * scale + offset << ",3)" << endl;
}

void arrow(Line const &l) {
  auto r = rndgen.next(256), g = rndgen.next(256), b = rndgen.next(256);
  ofs << "line(" << l[0].real() * scale + offset << ","
      << l[0].imag() * scale + offset << "," << l[1].real() * scale + offset
      << "," << l[1].imag() * scale + offset << ",'rgb(" << r << "," << g << ","
      << b << ")')" << endl;
  check(l[1]);
}

void label(P &p, string t) {
  ofs << "draw_text(\"" << t << "\", " << p.real() * scale + offset << ","
      << p.imag() * scale + offset << ")" << endl;
}

void show_picture() {
  ofs.close();
  int r = system("open visualizer.html");
  assert(!WEXITSTATUS(r));
}
}

void drawlines(vector<Line> &line) {
  for (auto &e : line) {
    visualizer::line(e);
  }
}

void drawpts(vector<P> &pts) {
  for (auto &e : pts) {
    visualizer::point(e);
  }
}

namespace graph::visualizer {

using graph_type = vector<vector<pair<int, double>>>;

void directed_graph(graph_type &g, const string fname = "digraph") {
  const string gfname = "__graph_vis_out_" + fname + ".dot";
  ofstream ofs(gfname);
  ofs << "digraph {" << endl;
  rep(i, g.size()) rep(k, g[i].size()) {
    ofs << i << " -> " << g[i][k].first << ";" << endl;
  }
  ofs << "}" << endl;
  ofs.close();
  int r = system(("dot -Tpng " + gfname + " > " + fname + ".png").c_str());
  if (!WEXITSTATUS(r)) {
    r = system(("rm " + gfname).c_str());
    if (!WEXITSTATUS(r)) {
      //      r = system(("open " + fname + ".png").c_str()); assert(!r && "open
      //      error");
    } else
      assert(0 && "rm error");
  } else
    assert(0 && "dot error");
}
}

int N;
P src, dst;
vector<Line> line;
vector<vector<pair<int, double>>> G;
map<pair<int, int>, int> nd;
map<int, P> ndB;
int nsize;

template <class T> using PQ_G = priority_queue<T, vector<T>, greater<T>>;

void dijkstra(int s, int t) {

  vector<double> dist(222, inf);
  vector<int> prev(222, inf);
  dist[s] = 0;

  PQ_G<pair<double, int>> pq;
  pq.emplace(0, s);

  while (!pq.empty()) {
    double len;
    int pos;
    tie(len, pos) = pq.top();
    pq.pop();
    for (auto const &e : G[pos]) {
      int next;
      double plen;
      tie(next, plen) = e;
      //      cout << pos << " -> " << next << endl;
      if (dist[next] <= len + plen)
        continue;
      dist[next] = len + plen;
      prev[next] = pos;
      pq.emplace(dist[next], next);
    }
  }

  //  cout << s << ", " << t << endl;  cout << dist[s] << ", " << dist[t] <<
  //  endl;

  if (dist[t] == inf) {
    cout << -1 << endl;
  } else {
    vector<pair<int, int>> path;
    for (int pos = t; pos != s; pos = prev[pos]) {
      assert(pos != inf);
      path.emplace_back((int)ndB[pos].real(), (int)ndB[pos].imag());
    }
    cout << (int)ndB[s].real() << " " << (int)ndB[s].imag() << endl;
    //    cout << s << endl;
    reverse(all(path));
    for (auto &e : path)
      cout << e.first << " " << e.second << endl;
    //      cout << nd[e] << endl;
    cout << "0\n";
  }
}

bool merge_if_able(Line &s, Line t) {
  if (abs(cross(s[1] - s[0], t[1] - t[0])) > EPS)
    return false;
  if (ccw(s[0], t[0], s[1]) == +1 || ccw(s[0], t[0], s[1]) == -1)
    return false; // not on the same line
  if (ccw(s[0], s[1], t[0]) == -2 || ccw(t[0], t[1], s[0]) == -2)
    return false; // separated
  s = Line(min(s[0], t[0]), max(s[1], t[1]));
  return true;
}
void merge_segments(vector<Line> &segs) {
  for (int i = 0; i < segs.size(); ++i)
    if (segs[i][1] < segs[i][0])
      swap(segs[i][1], segs[i][0]);
  for (int i = 0; i < segs.size(); ++i)
    for (int j = i + 1; j < segs.size(); ++j)
      if (merge_if_able(segs[i], segs[j]))
        segs[j--] = segs.back(), segs.pop_back();
}

void split_segments(vector<Line> &segs, vector<P> const &pts) {
  vector<Line> nsegs;
  rep(i, segs.size()) {
    vector<P> v = {segs[i][0], segs[i][1]};
    rep(j, pts.size()) {
      if (intersect_sp(segs[i], pts[j]) && !equals(segs[i][0], pts[j]) &&
          !equals(segs[i][1], pts[j])) {
        //        cout << "check" << endl;
        v.push_back(pts[j]);
      }
    }
    sort(all(v));
    rep(i, v.size() - 1) { nsegs.push_back(Line(v[i], v[i + 1])); }
  }

  segs = nsegs;
}

void solve() {

  double x, y;
  cin >> x >> y;
  src = P(x, y);
  cin >> x >> y;
  dst = P(x, y);

  rep(i, N) {
    P p1;
    cin >> x >> y;
    p1 = P(x, y);
    P p2;
    cin >> x >> y;
    p2 = P(x, y);
    line.push_back(Line(p1, p2));
  }

  map<pair<int, int>, int> cnt;
  rep(i, N) {
    REP(j, i + 1, N) {
      if (intersect_ss(line[i], line[j])) {
        auto p = crosspoint(line[i], line[j]);
        cnt[{p.real(), p.imag()}]++;
      }
    }
  }

#define reg_node(node)                                                         \
  { nd[{node.real(), node.imag()}] = nsize, ndB[nsize++] = node; }

  reg_node(src);
  reg_node(dst);

#define new_node(p) nd.find({p.real(), p.imag()}) == nd.end()

  rep(i, N) {
    auto p = line[i][0];
    auto q = line[i][1];
    if (cnt[{p.real(), p.imag()}] > 0 && cnt[{q.real(), q.imag()}] > 0) {
      if (new_node(p))
        reg_node(p);
      if (new_node(q))
        reg_node(q);
    }
  }

#define road(l)                                                                \
  (nd.find({l[0].real(), l[0].imag()}) != nd.end() &&                          \
   nd.find({l[1].real(), l[1].imag()}) != nd.end())

  vector<Line> nl;

  set<int> del;

  rep(i, N) {
    if (road(line[i])) {
      REP(j, i + 1, N) {
        if (road(line[j])) {
          if (intersect_ss(line[i], line[j])) {
            auto cp = crosspoint(line[i], line[j]);
            if (new_node(cp))
              reg_node(cp);
            if (!(equals(cp, line[i][0]) || equals(cp, line[i][1])) &&
                (equals(cp, line[j][0]) || equals(cp, line[j][1]))) {
              nl.push_back(Line(line[i][0], cp));
              nl.push_back(Line(line[i][1], cp));
              del.insert(i);
            } else if ((equals(cp, line[i][0]) || equals(cp, line[i][1])) &&
                       !(equals(cp, line[j][0]) || equals(cp, line[j][1]))) {
              nl.push_back(Line(line[j][0], cp));
              nl.push_back(Line(line[j][1], cp));
              del.insert(j);
            } else /*if((equals(cp, line[i][0]) || equals(cp, line[i][1])) &&
//               (equals(cp, line[j][0]) || equals(cp, line[j][1])))*/ {
            }
          }
        }
      }
    }
  }

  vector<Line> signs;

  rep(i, N) {
    if (road(line[i]) && !del.count(i))
      nl.push_back(line[i]);
    if (!road(line[i])) {
      auto sign = line[i];
      rep(k, line.size()) {
        if (road(line[k]) && intersect_ss(line[k], sign)) {
          auto cp = crosspoint(line[k], sign);
          if (equals(sign[1], cp))
            swap(sign[0], sign[1]);
          signs.push_back(sign);
          break;
        }
      }
    }
  }

  merge_segments(nl);
  vector<P> pts;
  for (auto &e : nd)
    pts.push_back(P(e.first.first, e.first.second));
  split_segments(nl, pts);

  sort(all(nl));
  nl.erase(unique(all(nl)), nl.end());
/*
  visualizer::init();  drawlines(nl);  drawlines(signs);

  for(auto& e: nd) {
    P k = P(e.first.first, e.first.second);
    visualizer::point(k);
    visualizer::label(k, to_string(nd[{k.real(),k.imag()}]));
  }
*/

#define corresponds_sign(r, s) intersect_ss(r, s)

  auto can_go = [&](P p, P s, P o) { return dot(p - s, o - s) > EPS; };

  set<pair<int, int>> invalids;

  rep(i, nl.size()) {
    rep(j, signs.size()) {
      if (corresponds_sign(nl[i], signs[j])) {
        auto &tar = nl[i];
        auto &sign = signs[j];
        if (!can_go(tar[0], sign[0], sign[1]))
          invalids.insert({nd[{tar[0].real(), tar[0].imag()}],
                           nd[{tar[1].real(), tar[1].imag()}]});

        if (!can_go(tar[1], sign[0], sign[1]))
          invalids.insert({nd[{tar[1].real(), tar[1].imag()}],
                           nd[{tar[0].real(), tar[0].imag()}]});
      }
    }
  }

  rep(i, nl.size()) {
    auto &tar = nl[i];
    auto s = nd[{tar[0].real(), tar[0].imag()}];
    auto t = nd[{tar[1].real(), tar[1].imag()}];
    if (!invalids.count({s, t}))
      G[s].emplace_back(t, abs(tar[0] - tar[1]));
    if (!invalids.count({t, s}))
      G[t].emplace_back(s, abs(tar[0] - tar[1]));
  }

  //  graph::visualizer::directed_graph(G);  visualizer::show_picture();

  dijkstra(nd[{src.real(), src.imag()}], nd[{dst.real(), dst.imag()}]);
}

void init() {
  line.clear();
  G.resize(222);
  rep(i, 222) G[i].clear();
  nsize = 0;
  nd.clear();
  ndB.clear();
}

int main() {
  while (cin >> N && N) {
    init();
    solve();
  }
}