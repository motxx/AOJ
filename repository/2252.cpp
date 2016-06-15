#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string qw = "qwertasdfgzxcvb";

  string query;
  while (cin >> query && query != "#") {
    bool isL = qw.find(query[0]) != string::npos;
    int N = query.size();
    int ans = 0;
    for (int i = 1; i < N; i++) {
      if ((qw.find(query[i]) != string::npos) ^ isL) {
        ans++;
        isL = !isL;
      }
    }
    cout << ans << endl;
  }

  return 0;
}