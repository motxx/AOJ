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

bool less_than(char l, char r) {
  const string order = "023456789TJQKA";
  return order.find(l) < order.find(r);
}

int main() {
  for (char trump; cin >> trump;) {
    if (trump == '#') {
      break;
    }
    vector<string> cards[4];
    rep(t, 4) rep(i, 13) {
      string s;
      cin >> s;
      cards[t].push_back(s);
    }

    vector<int> points(4);
    int lead_t = 0;
    rep(i, 13) {
      vector<int> trump_ids;
      rep(t, 4) {
        if (cards[t][i][1] == trump) {
          trump_ids.push_back(t);
        }
      }
      if (trump_ids.size() == 1) {
        points[trump_ids[0]]++;
        lead_t = trump_ids[0];
      } else if (trump_ids.size() > 1) {
        int mxid = -1;
        char max = '0';
        rep(k, trump_ids.size()) {
          if (less_than(max, cards[trump_ids[k]][i][0])) {
            max = cards[trump_ids[k]][i][0];
            mxid = trump_ids[k];
          }
        }
        points[mxid]++;
        lead_t = mxid;
      } else {
        int mxid = -1;
        char max = '0';
        rep(t, 4) {
          if (cards[lead_t][i][1] == cards[t][i][1]) {
            if (less_than(max, cards[t][i][0])) {
              max = cards[t][i][0];
              mxid = t;
            }
          }
        }
        points[mxid]++;
        lead_t = mxid;
      }
      //      rep(t, 4) cout << cards[t][i] << " "; cout << endl; rep(t, 4) cout
      //      << points[t] << " "; cout << endl;
    }

    if (points[0] + points[2] < points[1] + points[3]) {
      cout << "EW " << points[1] + points[3] - 6 << endl;
    } else {
      cout << "NS " << points[0] + points[2] - 6 << endl;
    }
  }

  return 0;
}