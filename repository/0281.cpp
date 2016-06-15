#include <iostream>
using namespace std;
int main() {
  int q;
  int c, a, n;

  cin >> q;
  while (q--) {
    int ans = 0;
    cin >> c >> a >> n;

    for (; c > 0;) {
      if (n > 0 && a > 0)
        ans++, n--, a--, c--;
      else if (a > 0 && c > 1)
        ans++, a--, c -= 2;
      else if (c > 2)
        c -= 3, ans++;
      else
        c = 0;
    }
    cout << ans << endl;
  }

  return 0;
}