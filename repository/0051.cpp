#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;

  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);

    int a[8], gr = 0, ls = 0;
    for (int j = 0; j < 8; j++) a[j] = str[j] - '0';
    sort(a, a + 8, greater<int>());
    for (int j = 0; j < 8; j++) {
      gr *= 10;
      gr += a[j];
    }
    sort(a, a + 8, less<int>());
    for (int j = 0; j < 8; j++) {
      ls *= 10;
      ls += a[j];
    }
    cout << gr - ls << endl;
  }

  return 0;
}