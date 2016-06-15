#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string str;
  const char *p;
  int res = 0;

  while (cin >> str) {
    p = &str[0];
    for (; p - &str[0] < (int)str.size(); p++) {
      if (isdigit(*p)) {
        char *e;
        int a;
        a = strtol(p, &e, 10);
        p = e;
        res += a;
      }
    }
  }

  cout << res << endl;

  return 0;
}