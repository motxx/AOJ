#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string s;
  while (cin >> s, s != "0") {
    int a = count(s.begin() + 1, s.end(), 'A');
    int b = count(s.begin() + 1, s.end(), 'B');
    if (a > b)
      a++;
    else
      b++;
    cout << a << ' ' << b << endl;
  }
  return 0;
}