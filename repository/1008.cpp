#include <iostream>
#include <map>

using namespace std;

#define REP(i, a, b) for (int i = a; i < int(b); i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N;
  while (cin >> N && N) {
    map<int, int> cnt;
    rep(i, N) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    bool ans = 0;
    for (auto i : cnt) {
      if (i.second > N / 2) {
        ans = 1;
        cout << i.first << endl;
      }
    }
    if (!ans) cout << "NO COLOR\n";
  }

  return 0;
}