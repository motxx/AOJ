#include <iostream>
using namespace std;
int main() {
  int n, q, y;
  cin >> n >> q;
  string s;
  const string S = "kogakubu10gokan";
  int f = 0;
  for (int i = 0; i < n; i++) {
    cin >> y;
    if (f) {
      cin >> s;
      continue;
    }
    if (i == 0 && q < y) {
      cout << S << endl;
      cin >> s;
      f = 1;
    } else if (q < y) {
      cout << s << endl;
      cin >> s;
      f = 1;
    } else
      cin >> s;
  }
  if (!f) cout << s << endl;
  return 0;
}