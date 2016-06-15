#include <iostream>
using namespace std;
int main() {
  int n, cnt[6] = {};
  double in;
  int temp;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    in -= 165;
    if (in < 0)
      cnt[0]++;
    else {
      temp = in;
      cnt[temp / 5 + 1]++;
    }
  }

  for (int i = 0; i < 6; i++) {
    cout << i + 1 << ":";
    for (int j = 0; j < cnt[i]; j++) cout << "*";
    cout << endl;
  }
  return 0;
}