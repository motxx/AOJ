#include <cmath>
#include <iostream>
using namespace std;

const long LIM = 1e9;

long long n, T, res;

int main() {
  cin >> n >> T;
  cin.ignore();
  string s;
  getline(cin, s);
  for (int i = 0; i < s.size();) {
    if (s[i] == 'n') {
      long long temp;
      for (int j = 0; j <= (s[i + 2] - '0'); j++) {
        temp = res + pow((double)n, j);
        if (temp > LIM) goto bad;
      }
      res = temp;
    }
    i += 4;
  }

  res *= T;
  if (res <= LIM) {
    cout << res << endl;
    return 0;
  }

bad:
  cout << "TLE" << endl;
  return 0;
}