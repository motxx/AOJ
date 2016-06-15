#include <iostream>
#include <string>
using namespace std;

int main() {
  string query;
  int cnt[101] = {0};  // empty
  char s[101][1001];
  int x, y;

  while (cin >> query) {
    if (query == "push") {
      cin >> x;
      cin >> s[x][++cnt[x]];
    } else if (query == "pop") {
      cin >> x;
      cout << s[x][cnt[x]] << endl;
      cnt[x]--;
    } else if (query == "move") {
      cin >> x;
      cin >> y;
      s[y][++cnt[y]] = s[x][cnt[x]];
      cnt[x]--;
    } else if (query == "quit")
      break;
  }

  return 0;
}