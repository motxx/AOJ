#include <iostream>

using namespace std;

int main(void) {
  int n, a, b;
  int scoreA, scoreB;

  while (1) {
    scoreA = 0;
    scoreB = 0;
    cin >> n;

    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (a > b) {
        scoreA += a + b;
      } else if (a == b) {
        scoreA += a;
        scoreB += b;
      } else {
        scoreB += a + b;
      }
    }

    cout << scoreA << " " << scoreB << endl;
  }

  return 0;
}