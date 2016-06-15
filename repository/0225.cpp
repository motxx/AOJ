#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int G[26][26];
int deg[26];
bool done[26];

void dfs(int s) {
  done[s] = true;
  for (int i = 0; i < 26; i++) {
    if (!done[i] && G[s][i]) dfs(i);
  }
}

int main() {
  int n, a, b;
  string str;

  while (cin >> n, n) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        G[i][j] = 0;
      }
      done[i] = true;
      deg[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      cin >> str;
      a = str[0] - 'a';
      b = str[str.size() - 1] - 'a';
      G[a][b] = 1;
      deg[a]++, deg[b]--;
      done[a] = done[b] = false;
    }

    dfs(a);

    // for(int i=0; i<26; i++) cout << done[i];
    // cout << endl;
    // for(int i=0; i<26; i++) cout << deg[i];
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (!done[i] || deg[i] != 0) flag = false;
    }
    if (flag)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }

  return 0;
}