#include <iostream>
#include <string>
using namespace std;

int main() {
  string query;
  int cnt = -1;  // empty
  char s[1000];

  while (cin >> query) {
    if (query == "push")
      cin >> s[++cnt];
    else if (query == "pop") {
      cout << s[cnt] << endl;
      cnt--;
    } else if (query == "quit")
      break;
  }

  return 0;
}