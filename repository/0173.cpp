#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    string name;
    int a, b;
    if (!(cin >> name >> a >> b)) break;
    cout << name << ' ' << a + b << ' ' << a * 200 + b * 300 << endl;
  }

  return 0;
}