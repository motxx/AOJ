#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define A_MAX 10000

int main(void) {
  int n;
  int a[10000] = {0};
  int i, j;

  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + 10000);

  for (i = 0; i < 10000; i++) {
    if (a[i] > 0) break;
  }
  int st = i - 1;

  // cout << a[st + 1] << endl;

  stringstream ss1, ss2, ss3, ss4;

  string str[4];
  string strAppended;
  int res[12];
  int cnt = 0;

  ss1 << a[st + 1];
  ss2 << a[st + 2];
  ss3 << a[st + 3];
  if (n == 3) {
    ss4 << A_MAX;
  } else {
    ss4 << a[st + 4];
  }
  str[0] = ss1.str();
  str[1] = ss2.str();
  str[2] = ss3.str();
  str[3] = ss4.str();

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (str[i] == str[j]) continue;

      strAppended = str[i] + str[j];
      // cout << "------" << strAppended << endl;
      res[cnt++] = atoi(strAppended.c_str());
    }
  }

  sort(res, res + 12);

  cout << res[2] << endl;

  return 0;
}