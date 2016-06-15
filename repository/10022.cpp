#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string fStr;
  string t;
  int cnt = 0;

  cin >> fStr;
  transform(fStr.begin(), fStr.end(), fStr.begin(), ::tolower);

  for (;;) {
    cin >> t;
    if (t == "END_OF_TEXT") break;

    transform(t.begin(), t.end(), t.begin(), ::tolower);
    if (t == fStr) cnt++;
  }

  cout << cnt << endl;
  return 0;
}