#include <cctype>
#include <iostream>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  bool f = 0, bad = 0;
  if (str.size() < 6) bad = 1;
  for (int i = 0; i < str.size(); i++)
    if (isdigit(str[i])) f = 1;
  if (!f) bad = 1;
  f = 0;
  for (int i = 0; i < str.size(); i++)
    if ('a' <= str[i]) f = 1;
  if (!f) bad = 1;
  f = 0;
  for (int i = 0; i < str.size(); i++)
    if ('A' <= str[i] && str[i] <= 'Z') f = 1;
  if (!f) bad = 1;
  cout << (bad ? "INVALID" : "VALID") << endl;
  return 0;
}