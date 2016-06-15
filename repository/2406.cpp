#include <iostream>

using namespace std;

int main(void) {
  int N, T, E;
  int x[10000];
  int flag = 0;
  int ans = -1;
  int temp;

  cin >> N >> T >> E;

  for (int i = 1; i <= N; i++) {
    cin >> x[i];
    temp = x[i];

    for (int j = 1; j <= N; j++) {
      if (flag == 0) {
        if (x[i] >= T - E && x[i] <= T + E) {
          flag = 1;
          ans = i;
        }

        x[i] += temp;
      }
    }
  }

  cout << ans << endl;

  return 0;
}