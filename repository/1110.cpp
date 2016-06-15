#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int H = 5, W = 4;

int countZero(const string &str) {
  int ret = 0;
  for (int i = 0; i < H * W; i++) {
    ret += str[i] == '0';
  }

  return ret;
}

void rearrange(string &str) {
  int pos = 0;
  for (int i = 0; i < H * W; i++) {
    if (str[i] == '0') continue;
    char ch = str[i];
    str[i] = '0';
    str[pos++] = ch;
  }
}

int main() {
  int Tc;
  cin >> Tc;

  while (Tc--) {
    string initial;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        char ch;
        cin >> ch;
        initial += ch;
      }
    }

    int ans = 0;

    set<string> used;
    queue<string> Q;
    Q.push(initial);
    while (!Q.empty()) {
      const string now = Q.front();
      Q.pop();
      ans = max(ans, countZero(now));
      for (int pos = 0; pos < H * W; pos++) {
        if (now[pos] == '0') continue;
        int x = pos % W, y = pos / W;
        for (int k = 0; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;
            const int ny = y + k, nx = x + l;
            if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
            const int npos = ny * W + nx;
            if (now[pos] != now[npos]) continue;
            string next;
            for (int i = 0; i < H * W; i++) {
              if (i == pos || i == npos) continue;
              next += now[i];
            }
            next += "00";
            if (used.count(next)) continue;
            used.insert(next);
            Q.push(next);
          }
        }
      }
    }
    cout << 20 - ans << endl;
  }

  return 0;
}