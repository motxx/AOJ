#include <bits/stdc++.h>

using namespace std;

struct C {
  int w, d;
  C(int w, int d) : w(w), d(d) {}
  bool operator<(const C& c) const { return w * d < c.w * c.d; }
};

int main() {
  int N, W, D;
  while (cin >> N >> W >> D && (N | W | D)) {
    vector<C> cs;
    cs.push_back(C(W, D));
    while (N--) {
      int p, s;
      cin >> p >> s;
      p--;
      C c = cs[p];
      cs.erase(cs.begin() + p);
      s %= (c.w + c.d) * 2;
      int rem = s, ang = -1;
      for (int i = 0; i < 2; i++) {
        ang++;
        rem -= c.w;
        if (rem < 0) break;
        ang++;
        rem -= c.d;
        if (rem < 0) break;
      }

      rem = -rem;

      if (ang == 0 || ang == 2) {
        int a = rem, b = c.w - a;
        if (b < a) swap(a, b);
        cs.push_back(C(a, c.d));
        cs.push_back(C(b, c.d));
      } else {
        int a = rem, b = c.d - a;
        if (b < a) swap(a, b);
        cs.push_back(C(c.w, a));
        cs.push_back(C(c.w, b));
      }
    }
    sort(cs.begin(), cs.end());
    for (int i = 0; i < cs.size(); i++) {
      if (i) cout << ' ';
      cout << cs[i].w * cs[i].d;
    }
    cout << endl;
  }
  return 0;
}