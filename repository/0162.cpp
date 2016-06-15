#include <bits/stdc++.h>
using namespace std;

set<int> hamming;
void make_hamming() {
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      for (int k = 0; k < 20; k++)
        hamming.insert(pow(2.0, i) * pow(3.0, j) * pow(5.0, k));
}

int main() {
  make_hamming();
  int m, n;
  while (cin >> m >> n && m) {
    set<int>::iterator it = hamming.begin();
    int cnt = 0;
    for (it; it != hamming.end(); it++) {
      if (m <= *it && *it <= n) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}