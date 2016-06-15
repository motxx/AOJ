#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

int main() {
  string str;
  char *e;
  const char *p;
  int a;
  map<int, int> mp1, mp2, mp3;

  while (getline(cin, str)) {
    if (str == "") break;
    p = &str[0];
    a = strtol(p, &e, 10);
    mp1[a]++;
    mp3[a]++;
  }

  while (getline(cin, str)) {
    p = &str[0];
    a = strtol(p, &e, 10);
    mp2[a]++;
    mp3[a]++;
  }

  for (map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) {
    if (mp1[it->first] && mp2[it->first]) {
      cout << it->first << " " << it->second << endl;
    }
  }

  return 0;
}