#include <iostream>

using namespace std;

int main(void) {
  string target;
  int n;
  string str;
  string strAppended;

  cin >> target;
  cin >> n;

  int lenT = target.length();
  int lenAp;
  int count = 0;

  for (int j = 0; j < n; j++) {
    cin >> str;

    strAppended = str + str;  // cout << "---" << strAppended << endl;;
    lenAp = strAppended.length();

    for (int i = 0; i < lenAp; i++) {
      if (target.substr(0, 1) == strAppended.substr(i, 1)) {
        // cout << "pass1" << endl;
        if (target == strAppended.substr(i, lenT)) {
          // cout << "---" << strAppended.substr(i, lenT) << endl;
          count++;
          break;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}