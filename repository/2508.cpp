#include <iostream>
using namespace std;

int main() {
  int n;
  int key[100];
  string s;

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) cin >> key[i];
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
      int temp = key[i % n];
      while (temp--) {
        if (s[i] == 'a')
          s[i] = 'Z';
        else if (s[i] == 'A')
          s[i] = 'z';
        else
          s[i]--;
      }
    }

    cout << s << endl;
  }

  return 0;
}