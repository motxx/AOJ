#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;

  while (getline(cin, str)) {
    if (str == "END OF INPUT") break;

    int res = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ' ') {
        cout << res;
        res = 0;
      } else {
        res++;
      }
    }
    cout << res << endl;
  }

  return 0;
}