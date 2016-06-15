#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

enum { VTop, HLeft, VBottom };

struct P {
  int x, y;
  int type;
  int oppo_x;
  bool operator<(P const& p) const {
    if (y != p.y) return y < p.y;
    if (type != p.type) {
      return type < p.type;
    }
    return x < p.x;
  }
};

struct Line : public vector<P> {
  Line(P const& a, P const& b) { push_back(a), push_back(b); }
};

void print(vector<P> const& pts) {
  int F[10][10] = {};
  rep(i, pts.size()) {
    if (pts[i].type != HLeft) {
      if (pts[i].type == VTop) {
        REP(j, pts[i].y, 10) { F[j][pts[i].x] = 1; }
      } else {
        REP(j, pts[i].y + 1, 10) { F[j][pts[i].x] = 0; }
      }
    }
  }
  rep(i, pts.size()) {
    if (pts[i].type == HLeft) {
      REP(j, pts[i].x, pts[i].oppo_x + 1) { F[pts[i].y][j] = 1; }
    }
  }
  rep(i, 10) {
    rep(j, 10) { cout << (F[i][j] ? "#" : "_"); }
    cout << endl;
  }
}

int main() {
  int N;
  cin >> N;
  vector<P> pts;
  rep(i, N) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    int type1, type2;
    if (x1 == x2) {
      type1 = VTop, type2 = VBottom;
      pts.push_back((P){x1, y1, type1, -1});
      pts.push_back((P){x2, y2, type2, -1});
    } else {
      type1 = HLeft;
      pts.push_back((P){x1, y1, type1, x2});
    }
  }

  sort(pts.begin(), pts.end());

  int ret = 0;
  set<int> xtree;
  for (auto p : pts) {
    if (p.type == VTop) {
      xtree.insert(p.x);
    }
    if (p.type == VBottom) {
      xtree.erase(p.x);
    }
    if (p.type == HLeft) {
      int const x1 = p.x, x2 = p.oppo_x;
      auto iter1 = xtree.lower_bound(x1);
      auto iter2 = xtree.upper_bound(x2);

      int cnt = 0;
      while (iter1 != iter2) {
        iter1++;
        cnt++;
      }
      ret += cnt;
    }
  }

  cout << ret << endl;

  return 0;
}