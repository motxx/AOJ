#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string t[3] = {"the", "this", "that"};
  string str;

  while (getline(cin, str)) {
    while (1) {
      for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ' && str[i] != '.')
          str[i] = (str[i] - 'a' + 1) % 26 + 'a';
      for (int i = 0; i < 3; i++)
        if (str.find(t[i]) != string::npos) goto fi;
    }
  fi:
    cout << str << endl;
  }
  return 0;
}