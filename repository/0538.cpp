#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, k;
  string str;

  while (cin >> n, n) {
    string key = "I";
    for (int i = 0; i < n; i++) key += "OI";

    cin >> k >> str;
    int cnt = 0;
    for (int i = 0; i < k - key.size(); i++) {
      if (str.substr(i, key.size()) == key) cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}