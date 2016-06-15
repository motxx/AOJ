#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;

  cin >> n;

  set<string> s;
  set<string>::iterator it;
  char query[5];
  string str;

  for (int i = 0; i < n; i++) {
    scanf("%s", query);
    if (query[0] == 'i') {
      cin >> str;
      s.insert(str);
    } else {
      cin >> str;
      it = s.find(str);
      if (it == s.end())
        cout << "no" << endl;
      else
        cout << "yes" << endl;
    }
  }

  return 0;
}