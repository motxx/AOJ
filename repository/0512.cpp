#include <iostream>
#include <string>
using namespace std;

int main() {
  char aft[26];

  aft[0] = 'X';
  aft[1] = 'Y';
  aft[2] = 'Z';
  for (int i = 0; i < 23; i++) aft[i + 3] = 'A' + i;

  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++) str[i] = aft[str.at(i) - 'A'];

  cout << str << endl;

  return 0;
}