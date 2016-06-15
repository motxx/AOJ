#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1001;
int V, d;

unsigned F[1002];

int main() {
  while (cin >> V >> d) {
    F[0] = 2;
    F[1] = 3;
    for (int i = 2; i < 1001; i++) {
      F[i] = (F[i - 1] + F[i - 2]) % N;
    }
    sort(F, F + V);

    int ans = 1;

    for (int i = 0; i < V; i++) {
      if (i > 0 && F[i] - F[i - 1] >= d) {
        ans++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}