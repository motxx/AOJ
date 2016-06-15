#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

struct Vector {
  int x, y;
  Vector() {}
  Vector(int x, int y) : x(x), y(y) {}

  double norm() { return x * x + y * y; }
};

typedef vector<Vector> vv;

Vector rotate90R(Vector v) { return Vector(-v.y, v.x); }

int lcm(int a, int b) { return (a * b) / __gcd(a, b); }

bool isEqVecs(vv vv1, vv vv2) {
  int a, b, l;
  l = lcm(vv1[0].norm(), vv2[0].norm());
  a = l / vv1[0].norm();  // ﾃ･ﾂ?催ｧﾂ篠?
  b = l / vv2[0].norm();

  if (vv1.size() != vv2.size())
    return false;  // ﾃ｣ﾂδ凖｣ﾂつｯﾃ｣ﾂδ暗｣ﾂδｫﾃ｣ﾂ?ｮﾃｦﾂ閉ｰﾃ｣ﾂ?古ｧﾂ閉ｰﾃ｣ﾂ?ｪﾃ｣ﾂつ?

  bool isok = true;
  // ﾃｦﾂｯﾂ氾ｧﾂ篠?｣ﾂ?古ｯﾂｼﾂ敕｣ﾂ?凝ｨﾂｪﾂｿﾃ｣ﾂ?ｹﾃ｣ﾂつ?
  for (int i = 0; i < vv1.size(); i++) {
    if (!(vv1[i].x * a == vv2[i].x * b && vv1[i].y * a == vv2[i].y * b))
      isok = false;
  }

  return isok;
}

int main() {
  int n;

  // input data
  while (cin >> n && n) {
    vv vvec[51][8];
    int id2m[51];
    Vector data[51];

    for (int id = 0; id <= n; id++) {
      cin >> id2m[id];
      for (int j = 0; j < id2m[id]; j++) {
        cin >> data[j].x >> data[j].y;
      }

      for (int j = 1; j < id2m[id]; j++) {
        Vector V1(data[j].x - data[j - 1].x, data[j].y - data[j - 1].y);
        Vector V2(-(data[id2m[id] - 1 - j].x - data[id2m[id] - j].x),
                  -(data[id2m[id] - 1 - j].y - data[id2m[id] - j].y));
        vvec[id][0].pb(V1);
        vvec[id][1].pb(rotate90R(vvec[id][0][j - 1]));
        vvec[id][2].pb(rotate90R(vvec[id][1][j - 1]));
        vvec[id][3].pb(rotate90R(vvec[id][2][j - 1]));

        vvec[id][4].pb(V2);
        vvec[id][5].pb(rotate90R(vvec[id][4][j - 1]));
        vvec[id][6].pb(rotate90R(vvec[id][5][j - 1]));
        vvec[id][7].pb(rotate90R(vvec[id][6][j - 1]));
      }

      /*
        for(int k=0; k<4; k++) {
        for(int v_i=0; v_i<id2m[id]-1; v_i++) {
        cout << vvec[id][k][v_i].x << ' ' << vvec[id][k][v_i].y << endl;
        }
        }
      */
    }

    for (int i = 1; i <= n; i++) {
      // Obj(id = 0) ﾃ｣ﾂ?ｨ Obj(for all except id = 0) * 8
      // ﾃ｣ﾂ?ｨﾃ｣ﾂ?ｮﾃ､ﾂｸﾂ?ｨﾂ?ｴﾃ｣ﾂつ津ｨﾂｪﾂｿﾃ｣ﾂ?ｹﾃ｣ﾂつ?
      for (int k = 0; k < 8; k++) {
        if (isEqVecs(vvec[i][k], vvec[0][0])) {
          cout << i << endl;
        }
      }
    }
    cout << "+++++" << endl;
  }

  return 0;
}