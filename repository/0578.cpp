#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, ans;
  string key, str;

  cin >> n >> key;
  int t = key.size();

  ans = 0;
  for (int I = 0; I < n; I++) {
    cin >> str;
    int s = str.size();

    bool ok = false;
    for (int space = 0; space < s; space++) {
      for (int st = 0; st < s; st++) {
        int cnt = 0;
        for (int kidx = 0; kidx < t; kidx++) {
          if (st + kidx * space + kidx < s)
            if (key[kidx] == str[st + kidx * space + kidx]) {
              cnt++;
            }
        }
        if (cnt == t) {
          ok = true;
        }
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;

  return 0;
}