#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    vector<string> vec[30];
    string s[30];
    for (int ii = 0; ii < N; ii++) {
      cin >> s[ii];
      int m, d;
      cin >> m;
      for (int i = 0; i < m; i++) {
        cin >> d;
        vec[d].push_back(s[ii]);
      }
    }

    map<string, int> score;

    for (int i = 0; i < N; i++) {
      score[s[i]] = 0;
    }

    for (int i = 0; i < 30; i++)
      for (int j = 0; j < (int)vec[i].size(); j++)
        score[vec[i][j]] += N - vec[i].size() + 1;

    vector<pair<int, string> > ans;
    map<string, int>::iterator it = score.begin();
    for (; it != score.end(); it++) {
      ans.push_back(make_pair(it->second, it->first));
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].first << ' ' << ans[0].second << endl;
  }
  return 0;
}