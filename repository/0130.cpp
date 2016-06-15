#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    string str;
    cin >> str;
    list<char> li;
    list<char>::iterator it;
    inserter(li, li.end()) = str[0];
    for (int i = 3; i < str.size(); i += 3) {
      if (find(li.begin(), li.end(), str[i]) != li.end()) continue;
      it = find(li.begin(), li.end(), str[i - 3]);
      if (str[i - 1] == '>')
        inserter(li, ++it) = str[i];
      else
        inserter(li, it) = str[i];
    }

    for (it = li.begin(); it != li.end(); it++) {
      cout << *it;
    }
    cout << endl;
  }

  return 0;
}