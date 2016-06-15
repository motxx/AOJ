#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  string D = "AIDUNYAN";
  sort(D.begin(), D.end());

  string const azupero = "AIZUNYAN";

  cin >> s;
  int size = s.size();

  for (int i = 0; i < size; i++) {
    string sub = s.substr(i, 8);
    sort(sub.begin(), sub.end());
    if (sub == D) {
      for (int j = 0; j < 8; j++) {
        s[i + j] = azupero[j];
      }
      i += 7;
    }
  }

  cout << s << endl;

  return 0;
}