#include <iostream>
using namespace std;

int main() {
  string str;

  getline(cin, str);

  for (int i = 0; i < str.size(); i++) {
    if ('a' <= str[i] && str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
    cout << str[i];
  }
  cout << endl;
  return 0;
}