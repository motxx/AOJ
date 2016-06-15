#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool cmp(const string &a, const string &b) {
  if (a.size() != b.size()) return a.size() < b.size();

  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i]) return a[i] < b[i];

  return true;
}

string dp[71][71];

int main() {
  int W, H;

  while (cin >> W >> H && (W | H)) {
    for (int i = 0; i <= H; i++)
      for (int j = 0; j <= W; j++) dp[i][j] = "0";

    string ans = "0";

    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        char c;
        cin >> c;
        if (isdigit(c)) {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], cmp);

          if (dp[i][j] == "0") dp[i][j] = "";

          dp[i][j] += c;
        } else
          dp[i][j] = "";
        ans = max(ans, dp[i][j], cmp);
      }
    }
    cout << ans << endl;
  }

  return 0;
}