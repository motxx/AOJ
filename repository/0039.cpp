#include <iostream>
using namespace std;
int c2i[256];

void init() {
  c2i['I'] = 1;
  c2i['V'] = 5;
  c2i['X'] = 10;
  c2i['L'] = 50;
  c2i['C'] = 100;
  c2i['D'] = 500;
  c2i['M'] = 1000;
}

int main() {
  init();

  string str;
  while (getline(cin, str)) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
      if (c2i[str[i]] < c2i[str[i + 1]]) {
        res -= c2i[str[i]];
      } else {
        res += c2i[str[i]];
      }
    }
    cout << res << endl;
  }

  return 0;
}