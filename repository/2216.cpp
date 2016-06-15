#include <iostream>

using namespace std;

int main(void) {
  int a, b, c;
  int mon;
  int turi[3], turiidx;

  for (;;) {
    cin >> a >> b;
    if (a == 0 && b == 0) break;

    c = b - a;
    turiidx = 0;
    turi[0] = 0;
    turi[1] = 0;
    turi[2] = 0;

    mon = 1000;
    for (;;) {
      if (c - mon < 0) {
        switch (mon) {
          case 1000:
            mon = 500;
            turiidx = 1;
            continue;
          case 500:
            mon = 100;
            turiidx = 2;
            continue;
          case 100:
            goto printres;
        }
      }
      c -= mon;
      turi[turiidx]++;
    }

  printres:
    cout << turi[2] << " " << turi[1] << " " << turi[0] << endl;
  }

  return 0;
}