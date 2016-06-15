#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string str;
  int n;

  while (1) {
    cin >> str;
    if (str == "-") break;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;
      string left = str.substr(0, l);
      str = str.substr(l, str.length()) + left;
    }

    cout << str << endl;
  }
  return 0;
}