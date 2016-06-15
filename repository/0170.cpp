#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    string name[N];
    int weight[N], strength[N];

    for (int i = 0; i < N; i++) cin >> name[i] >> weight[i] >> strength[i];

    int per[N];
    for (int i = 0; i < N; i++) per[i] = i;
    int save[N];
    for (int i = 0; i < N; i++) save[i] = i;

    int mx = 0;
    int mxG = 0;

    do {
      int sum_weight = weight[per[0]];
      int G = weight[per[0]];
      bool ok = 1;
      for (int i = 1; i < N; i++) {
        if (sum_weight <= strength[per[i]]) {
          sum_weight += weight[per[i]];
          G += (i + 1) * weight[per[i]];
        } else {
          ok = 0;
          break;
        }
      }

      if (ok) {
        if (G > mxG) {
          mxG = G;
          for (int i = 0; i < N; i++) save[i] = per[i];
        }
      }

    } while (next_permutation(per, per + N));

    for (int i = N - 1; i >= 0; i--) {
      cout << name[save[i]] << endl;
    }
  }

  return 0;
}