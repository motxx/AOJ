#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int usagi[1000001];
int neko[1000001];
int Ru[500], Cu[500], Du[2];
int Rn[500], Cn[500], Dn[2];

int main() {
  int N, U, V, M;
  cin >> N >> U >> V >> M;
  rep(i, 1000001) usagi[i] = neko[i] = -1;
  rep(i, N) rep(j, N) {
    int x;
    scanf("%d", &x);
    usagi[x] = i * N + j;
  }
  rep(i, N) rep(j, N) {
    int x;
    scanf("%d", &x);
    neko[x] = i * N + j;
  }

  int u = 0, v = 0;

  rep(_, M) {
    int card;
    scanf("%d", &card);
    if (~usagi[card]) {
      int a = usagi[card] / N;
      Ru[a]++;
      int b = usagi[card] % N;
      Cu[b]++;
      if (a == b) Du[0]++;
      if (a == N - 1 - b) Du[1]++;
      if (Ru[a] == N) u++, Ru[a] = -1;
      if (Cu[b] == N) u++, Cu[b] = -1;
      if (Du[0] == N) u++, Du[0] = -1;
      if (Du[1] == N) u++, Du[1] = -1;
    }
    if (~neko[card]) {
      int a = neko[card] / N;
      Rn[a]++;
      int b = neko[card] % N;
      Cn[b]++;
      if (a == b) Dn[0]++;
      if (a == N - 1 - b) Dn[1]++;
      if (Rn[a] == N) v++, Rn[a] = -1;
      if (Cn[b] == N) v++, Cn[b] = -1;
      if (Dn[0] == N) v++, Dn[0] = -1;
      if (Dn[1] == N) v++, Dn[1] = -1;
    }
    if (N == 1) {
      u = min(1, u), v = min(1, v);
      if (!((u == 1 && U == 1) || (v == 1 && V == 1))) continue;
      if (u == 1 && v == 1 && U == V && U == 1) {
        cout << "DRAW" << endl;
        return 0;
      } else if (u == 1 && U == 1) {
        cout << "USAGI" << endl;
        return 0;
      } else if (v == 1 && V == 1) {
        cout << "NEKO" << endl;
        return 0;
      } else {
        cout << "DRAW" << endl;
        return 0;
      }
    } else if (U <= u && V > v) {
      cout << "USAGI" << endl;
      return 0;
    } else if (U > u && V <= v) {
      cout << "NEKO" << endl;
      return 0;
    } else if (U <= u && V <= v) {
      break;
    }
  }

  cout << "DRAW" << endl;

  return 0;
}