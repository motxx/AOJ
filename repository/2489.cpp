#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(string s) { return equal(s.begin(), s.end(), s.rbegin()); }

int main() {
  int n;
  cin >> n;
  string ans;
  for (int i = 0;; i++) {
    int data = n - i;

    if (data < 0) {
    } else {
      stringstream ss;
      ss << data;
      if (isPalindrome(ss.str())) {
        ans = ss.str();
        break;
      }
    }

    data = n + i;
    stringstream ss;
    ss << data;
    if (isPalindrome(ss.str())) {
      ans = ss.str();
      break;
    }
  }

  cout << ans << endl;

  return 0;
}