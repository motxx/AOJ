#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int const INF = 1 << 29;

struct frame {
  int fx, fy;
  int tx, ty;
  int id;

  frame(int fx, int fy, int tx, int ty, int id)
      : fx(fx), fy(fy), tx(tx), ty(ty), id(id) {}
};

inline bool cmpx(frame const& a, frame const& b) {
  if (a.fx != b.fx) return a.fx < b.fx;
  if (a.ty != b.ty) return a.ty < b.ty;
  return a.tx < b.tx;
}

int anscnt, ans[110];

void rec(vector<frame> curr) {
  if (curr.empty()) {
    return;
  }
  sort(curr.begin(), curr.end(), cmpx);

  frame tar = curr[0];
  ans[tar.id] = anscnt++;
  curr.erase(curr.begin());

  bool hit = 0;
  int rx = tar.tx;
  rep(i, curr.size()) {
    if (curr[i].ty == tar.ty) {
      rx = curr[i].tx;
    } else if (curr[i].fy >= tar.ty) {
    } else if (rx < curr[i].tx && curr[i].ty > tar.ty) {
      hit = 1;
      break;
    }
  }

  if (!hit) {
    rx = INF;
  }

  //  cerr << "tar.id: " << tar.id << ", " << tar.tx << " "<< rx << endl;

  vector<int> check(curr.size());
  rep(i, curr.size()) {
    if (curr[i].fx < rx && curr[i].ty <= tar.ty) {
      check[i] = 1;
    }
  }

  vector<frame> L, T;
  rep(i, curr.size()) {
    if (check[i]) {
      L.push_back(curr[i]);
    } else {
      T.push_back(curr[i]);
    }
  }

  //  cerr << "Lsize: " << L.size() << ", Tsize: " << T.size() << endl;

  rec(L), rec(T);
}

int main() {
  bool blank = 0;
  int N;
  while (cin >> N && N) {
    if (blank) {
      cout << endl;
    }
    blank = 1;
    anscnt = 1;
    vector<frame> v;
    rep(i, N) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      v.push_back(frame(x1, y1, x2, y2, i + 1));
    }
    rec(v);
    REP(i, 1, N + 1) cout << ans[i] << endl;
  }

  return 0;
}