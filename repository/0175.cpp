#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;

  while (cin >> N && N != -1) {
    string s;

    if (N == 0) s = "0";
    while (N > 0) {
      s = (char)('0' + (N % 4)) + s;
      N /= 4;
    }

    cout << s << endl;
  }

  return 0;
}