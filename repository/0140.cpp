#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n, s, t;
  cin >> n;

  rep(i, n) {
    cin >> s >> t;
    if (s <= 5) {
      if (s < t) {
        cout << s;
        for (int j = s + 1; j <= t; j++) cout << " " << j;
        cout << endl;
      }
      if (s > t) {
        cout << s;
        for (int j = s - 1; j >= t; j--) cout << " " << j;
        cout << endl;
      }
    } else {
      if (t <= 5) {
        for (int j = s; j < 10; j++) cout << j << " ";
        s = 5;
        cout << s;
        for (int j = s - 1; j >= t; j--) cout << " " << j;
        cout << endl;
      } else if (s < t) {
        cout << s;
        for (int j = s + 1; j <= t; j++) cout << " " << j;
        cout << endl;
      } else {
        for (int j = s; j < 10; j++) cout << j << " ";
        cout << "5 4 3 2 1 0 1 2 3 4 5";
        for (int j = 6; j <= t; j++) cout << " " << j;
        cout << endl;
      }
    }
  }

  return 0;
}