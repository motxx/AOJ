#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  string ret;

  bool flag = false;
  while (cin >> str) {
    if (flag) ret += " ";

    flag = true;

    size_t fpos = str.find("apple");
    if (fpos != string::npos) {
      str = str.substr(0, fpos) + "peach" +
            str.substr(fpos + 5, str.size() - fpos - 5);
    } else {
      fpos = str.find("peach");
      if (fpos != string::npos) {
        str = str.substr(0, fpos) + "apple" +
              str.substr(fpos + 5, str.size() - fpos - 5);
      }
    }

    ret += str;
  }

  cout << ret << endl;

  return 0;
}