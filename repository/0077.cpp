#include <iostream>
using namespace std;

int main() {
  string str;
  int len;
  int temp;

  while (getline(cin, str)) {
    len = str.size();
    for (int i = 0; i < len; i++) {
      if (str[i] == '@') {
        temp = str[i + 1] - '0';
        for (int j = 0; j < temp; j++) {
          cout << str[i + 2];
        }
        i += 2;
      } else {
        cout << str[i];
      }
    }
    cout << endl;
  }

  return 0;
}