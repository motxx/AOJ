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

int main() {
  int t;
  string num;
  for (; cin >> t >> num;) {
    if (t == 0 && num == "0") {
      break;
    }
    if (t == stoi(num)) {
      cout << t << " " << t << endl;
      continue;
    }

    int n = num.size();

    int asum = -1;
    int dcnt = 0;
    deque<int> part;
    std::function<void(int, int, deque<int> &)> divide = [&](int x, int idx,
                                                             deque<int> &dl) {
      if (idx == n) {
        if (t >= x) {
          if (maximize(asum, x)) {
            dcnt = 0;
            part = dl;
          } else {
            if (asum == x) {
              dcnt++;
            }
          }
        }
        return;
      }

      REP(i, idx, n) {
        dl.push_back(i + 1);
        divide(x + stoi(string(num.begin() + idx, num.begin() + i + 1)), i + 1,
               dl);
        dl.pop_back();
      }
    };

    deque<int> dl = {0};
    divide(0, 0, dl);

    if (dcnt > 0) {
      cout << "rejected" << endl;
    } else if (asum == -1) {
      cout << "error" << endl;
    } else {
      cout << asum;
      rep(i, part.size() - 1) {
        cout << " " << string(num.begin() + part[i], num.begin() + part[i + 1]);
      }
      cout << endl;
    }
  }

  return 0;
}