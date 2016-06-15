#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  string str;

  cin >> n;
  cin.ignore();
  while (n--) {
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
      if (str.substr(i, 7) == "Hoshino") str[i + 6] = 'a';
    }
    cout << str << endl;
  }

  return 0;
}