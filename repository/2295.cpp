#include <algorithm>
#include <cmath>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

int N;

int main() {
  cin >> N;
  bool nogt1flag = true;
  deque<int> a;
  int zeros = 0, ones = 0, twos = 0, threes = 0, over3 = 0;
  rep(i, N) {
    int in;
    cin >> in;
    if (in == 0) {
      zeros++;
    }
    if (in == 1) {
      ones++;
    }
    if (in == 2) {
      twos++;
    }
    if (in == 3) {
      threes++;
    }
    if (in >= 2) {
      nogt1flag = false;
    }
    if (in >= 4) {
      a.push_back(in);
      over3++;
    }
  }

  if (nogt1flag) {
    if (ones == 0) {
      rep(i, N) cout << 0 << endl;
    } else {
      if (zeros % 2 == 0) {
        rep(i, zeros) cout << 0 << endl;
        rep(i, ones) cout << 1 << endl;
      } else {
        rep(i, zeros - 1) cout << 0 << endl;
        cout << 1 << endl << 0 << endl;
        rep(i, ones - 1) cout << 1 << endl;
      }
    }
    return 0;
  }

  sort(a.begin(), a.end());

  int ikenie = -1;
  if (zeros % 2 && ones == 0) {
    if (twos > 0) {
      twos--;
      ikenie = 2;
    } else if (threes > 0) {
      threes--;
      ikenie = 3;
    } else {
      over3--;
      ikenie = a[0];
      a.pop_front();
    }
  }

  if (threes == 1 && twos > 0 && over3 == 0) {
    rep(i, twos - 1) cout << 2 << endl;
    cout << 3 << endl;
    cout << 2 << endl;
    rep(i, threes - 1) cout << 3 << endl;
    rep(i, a.size()) cout << a[i] << endl;
  } else {
    rep(i, twos) cout << 2 << endl;
    rep(i, threes) cout << 3 << endl;
    rep(i, a.size()) cout << a[i] << endl;
  }

  if (ones > 0) {  // use wildcard 1
    if (zeros % 2 == 0) {
      rep(i, zeros) cout << 0 << endl;
      cout << 1 << endl;
    } else {
      rep(i, zeros - 1) cout << 0 << endl;
      cout << 1 << endl;
      if (zeros) cout << 0 << endl;
    }
    rep(i, ones - 1) cout << 1 << endl;
  } else {
    if (zeros % 2) {
      rep(i, zeros - 1) cout << 0 << endl;
      cout << ikenie << endl << 0 << endl;
    } else if (zeros % 2 == 0) {
      rep(i, zeros) cout << 0 << endl;
    }
  }

  return 0;
}