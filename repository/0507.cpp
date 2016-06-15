#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
void dfs(vector<int>& v, int prev, int rem) {
  if (rem == 0) {
    for (int i = 0; i < v.size(); i++) {
      if (i) cout << " ";
      cout << v[i];
    }
    cout << endl;
    return;
  }

  for (int i = min(prev, rem); i >= 1; i--) {
    v.push_back(i);
    dfs(v, i, rem - i);
    v.pop_back();
  }
}

int main() {
  while (cin >> N && N) {
    vector<int> v;
    dfs(v, N, N);
  }

  return 0;
}