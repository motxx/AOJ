#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  stringstream s;
  string str;
  int num;
  int n;
  int len;

  cin >> n;
  for (int cnt = 0; cnt < n; cnt++) {
    cout << "Case " << cnt + 1 << ":" << endl;
    cin >> num;
    for (int j = 0; j < 10; j++) {
      num *= num;
      s << num;
      s >> str;
      s.clear();
      s.str("");

      len = str.length();
      for (int i = 0; i < 8 - len; i++) str = "0" + str;
      num = 0;
      for (int i = 0; i < 4; i++) {
        num *= 10;
        num += str[2 + i] - '0';
      }
      cout << num << endl;
    }
  }
  return 0;
}