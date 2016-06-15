#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int i;
  double d[10000] = {};
  for (i = 0; cin >> d[i]; i++)
    ;
  sort(d, d + i, greater<int>());
  cout << d[0] - d[i - 1] << endl;
  return 0;
}