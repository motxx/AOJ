#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

pair<int, int> check(vector<int>& taro, vector<int>& hanako) {
  int a = 0, b = 0;
  rep(i, taro.size()) if (taro[i] != -1) { a++; }
  rep(i, hanako.size()) if (hanako[i] != -1) { b++; }

  if (a == 0 || b == 0) {
    return make_pair(b, a);
  }
  return make_pair(-1, -1);
}

int main() {
  int N;
  while (cin >> N && N) {
    vector<int> taro(N);
    rep(i, N) cin >> taro[i];
    sort(taro.begin(), taro.end());
    int j = 0, k = 0;
    vector<int> hanako(N);
    rep(i, 2 * N) {
      if (i + 1 == taro[j]) {
        j++;
      } else {
        hanako[k++] = i + 1;
      }
    }

    int now = 0;
    int turn = 0;
    for (;;) {
      j = 0, k = 0;
      if (turn) {
        while (k < N && now >= hanako[k]) {
          k++;
        }
        if (k == N) {
          now = 0;
        } else {
          now = hanako[k];
          hanako[k] = -1;
        }
      } else {
        while (j < N && now >= taro[j]) {
          j++;
        }
        if (j == N) {
          now = 0;
        } else {
          now = taro[j];
          taro[j] = -1;
        }
      }
      pair<int, int> res(check(taro, hanako));
      if (res.first != -1) {
        cout << res.first << '\n' << res.second << endl;
        break;
      }
      turn ^= 1;
    }
  }

  return 0;
}