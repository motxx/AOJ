#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;
typedef pair<double, P> C;
vector<C> circles;
#define FST first
#define SND second
typedef pair<P, P> S;
#define EPS (1e-5)

double dot(P a, P b) { return a.real() * b.real() + a.imag() * b.imag(); }

double cross(P a, P b) { return a.real() * b.imag() - a.imag() * b.real(); }

double distanceLP(S s, P a) {
  // d = |y||sin(th)| = |x||y|sin(th)/|x| = |cross(x, y)|/|x|
  return abs(cross(s.SND - s.FST, a - s.FST)) / abs(s.SND - s.FST);
}

double distanceSP(S s, P a) {
  // 2ベクトルのなす角が鈍角なら端点と１点との距離を返す
  if (dot(s.SND - s.FST, a - s.FST) < EPS) return abs(a - s.FST);
  if (dot(s.FST - s.SND, a - s.SND) < EPS) return abs(a - s.SND);

  return distanceLP(s, a);
}

int main() {
  int N;
  while (cin >> N && N) {
    circles.clear();
    circles.resize(N);
    for (int i = 0; i < N; i++) {
      int x, y, r;
      cin >> x >> y >> r;
      circles[i] = C(r, P(x, y));
    }
    int Q;
    cin >> Q;
    while (Q--) {
      int x, y;
      cin >> x >> y;
      P taro(x, y);
      cin >> x >> y;
      P ogre(x, y);
      for (int i = 0; i < N; i++) {
        if (distanceSP(S(taro, ogre), circles[i].SND) < circles[i].FST + EPS) {
          if (!(abs(circles[i].SND - taro) < circles[i].FST + EPS) ||
              !(abs(circles[i].SND - ogre) < circles[i].FST + EPS)) {
            cout << "Safe" << endl;
            goto EXIT;
          }
        }
      }

      cout << "Danger" << endl;

    EXIT:;
    }
  }

  return 0;
}