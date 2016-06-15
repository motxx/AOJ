#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int Tc;
  cin >> Tc;
  int ans = 0;
  while (Tc--) {
    int K;
    cin >> K;
    bool ok = 0;
    for (int x = 1; 2 * x * x + 2 * x <= K; x++)
      if ((K - x) % (2 * x + 1) == 0) {
        ok = 1;
        break;
      }
    if (!ok) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}