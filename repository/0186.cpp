#include <bits/stdc++.h>

using namespace std;

void failed() { cout << "NA" << endl; }

int main() {
  int Q1, B, C1, C2, Q2;

  while (cin >> Q1 >> B >> C1 >> C2 >> Q2) {
    if (Q1 == 0) break;
    int AizuCh = min(B / C1, Q2);
    int NCh = 0;
    for (;;) {
      if (AizuCh <= 0) {
        failed();
        break;
      }
      NCh = (B - AizuCh * C1) / C2;
      if (AizuCh + NCh >= Q1) {
        cout << AizuCh << ' ' << NCh << endl;
        break;
      } else
        AizuCh--;
    }
  }

  return 0;
}