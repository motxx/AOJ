#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> back[20];
  int front[20] = {};
  int m, n;

  cin >> m;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    back[x].push_back(y);
    front[y]++;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (!front[j]) {
        cout << j + 1 << endl;
        for (int k = 0; k < back[j].size(); k++) {
          front[back[j][k]]--;
        }
        front[j] = -1;
      }
    }
  }

  return 0;
}