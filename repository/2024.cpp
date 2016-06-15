#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
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

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int to_int(char c) {
  if (isdigit(c)) {
    return c - '0';
  }
  if (c == 'A') {
    return 11;
  }
  return 10;
}

bool test_ace17(int value, int ace11) {
  while (ace11) {
    if (value <= 17) {
      return true;
    }
    ace11--;
    value -= 10;
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    vector<int> in;
    rep(i, 10) {
      char c;
      cin >> c;
      in.push_back(to_int(c));
    }

    if (in[0] + in[1] == 21) {
      cout << "blackjack" << endl;
      continue;
    }
    if (in[0] + in[1] > 21) {
      in[0] -= 10;
    }

    REP(k, 1, 10) {
      int value = 0;
      int ace11 = 0;
      rep(i, k + 1) {
        value += in[i];
        ace11 += in[i] == 11;
      }
      while (value > 21 && ace11) {
        ace11--;
        value -= 10;
      }
      if (value > 21) {
        cout << "bust" << endl;
        break;
      }

      if (test_ace17(value, ace11)) {
        continue;
      }
      if (value <= 16) {
        continue;
      }
      cout << value << endl;
      break;
    }
  }

  return 0;
}