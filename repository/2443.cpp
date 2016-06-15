#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<string, int> P;

// const ll p10[11] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL,
// 10000000LL, 100000000LL, 1000000000LL, 10000000000LL};

int N;
// map<vector<int>, int> mp[2];
unordered_map<string, int> mp[2];

void bfs(const string& start, const int idx) {
  mp[idx][start] = 0;
  queue<P> Q;
  Q.push(P(start, 0));
  while (!Q.empty()) {
    // vector<int> now = Q.front().first;
    const string now = Q.front().first;
    const int cost = Q.front().second;
    Q.pop();

    const int ncost = cost + 1;
    if (ncost >= 5) continue;

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        /*
          撃墜ケース N = 10
        ll next = 0;
        for(int k=N-1; k>=0; k--) {
          if(i <= k && k <= j) {
            (next *= 10) += (now / p10[j-k+i]) % 10;
          }
          else {
            (next *= 10) += (now / p10[k]) % 10;
          }
        }
        */
        // cout << "(" << i << ", " << j << ") : " << now << " " << next <<
        // endl;
        string next = now;
        reverse(next.begin() + i, next.begin() + j);
        unordered_map<string, int>::iterator it = mp[idx].find(next);
        if (it != mp[idx].end()) {
          if (it->second < ncost) {
            continue;
          }
        }
        mp[idx][next] = ncost;
        Q.push(P(next, ncost));
      }
    }
  }
}

int main() {
  cin >> N;
  string str;
  str.resize(N);
  for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    str[i] = 'a' + in;
  }

  bfs(str, 0);

  sort(str.begin(), str.end());
  bfs(str, 1);

  int ans = N - 1;
  for (auto i : mp[0]) {
    unordered_map<string, int>::iterator it = mp[1].find(i.first);
    if (it != mp[1].end()) {
      ans = min(ans, i.second + it->second);
    }
  }

  cout << ans << endl;

  return 0;
}