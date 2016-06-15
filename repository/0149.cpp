#include <bits/stdc++.h>

using namespace std;

double arr[] = {-9999999, 0.2, 0.6, 1.1, 999999999};

int main() {
  double a, b;
  int cntL[4] = {};
  int cntR[4] = {};
  while (cin >> a >> b) {
    for (int i = 0; i < 4; i++) {
      if (arr[i] <= a && a < arr[i + 1]) cntL[3 - i]++;
      if (arr[i] <= b && b < arr[i + 1]) cntR[3 - i]++;
    }
  }
  for (int i = 0; i < 4; i++) cout << cntL[i] << " " << cntR[i] << endl;

  return 0;
}