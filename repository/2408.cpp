#include <algorithm>
#include <iostream>

using namespace std;

#define RMAX 50 * 49 / 2 + 1

int main(void) {
  int N, K, R, boat[51][51], bnynum[51], pq[RMAX][2], pqF, usa[51] = {0}, temp;

  cin >> N >> K;

  for (int j = 1; j <= K; j++) {
    cin >> bnynum[j];

    for (int i = 1; i <= bnynum[j]; i++) {
      cin >> boat[j][i];
    }
    sort(boat[j] + 1, boat[j] + 1 + bnynum[j]);
  }

  cin >> R;

  for (int i = 0; i < R; i++) {
    cin >> pq[i][0] >> pq[i][1];
  }

  for (int j = 1; j <= K; j++) {
    for (int r = 0; r < R; r++) {
      pqF = 0;
      for (int i = 1; i <= bnynum[j]; i++) {
        if (boat[j][i] == pq[r][pqF]) {
          if (pqF == 0) {
            pqF = 1;
            temp = boat[j][i];
          } else {
            usa[temp] = 1;
            usa[boat[j][i]] = 1;
            break;
          }
        }
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= 50; i++) {
    res += usa[i];
  }

  cout << res << endl;
  return 0;
}