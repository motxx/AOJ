#include <iostream>
using namespace std;

int main() {
  int p, q;
  while (cin >> p >> q) {
    bool num[1000000] = {};
    num[p] = 1;
    int pos[1000000] = {};
    pos[p] = -1;
    bool loop = 0;
    int cnt = 0;
    string t;
    while (1) {
      p *= 10;
      t += (char)(p / q + '0');
      p %= q;
      if (num[p] == 1) {
        loop = 1;
        break;
      }
      num[p] = 1;
      if (p == 0) break;
      pos[p] = cnt++;
    }

    cout << t << endl;

    if (loop) {
      int I;
      for (I = 0; I <= pos[p]; I++) {
        cout << ' ';
      }
      for (I; I < t.size(); I++) {
        cout << '^';
      }
      cout << endl;
    }
  }

  return 0;
}