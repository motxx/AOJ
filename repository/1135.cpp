#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int tc;

  cin >> tc;
  while (tc--) {
    int start, dur, n;
    cin >> start >> dur >> n;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int mom = start, inte = 0, kind, dif;
      double rat;
      cin >> kind >> rat >> dif;
      for (int j = 0; j < dur; j++) {
        inte += rat * mom;
        if (kind) {
          mom += inte;
          inte = 0;
        }
        mom -= dif;
      }
      mom += inte;
      ans = max(ans, mom);
    }
    cout << ans << endl;
  }

  return 0;
}