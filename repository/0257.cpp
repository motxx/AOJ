#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 1 && b == 0 && c == 0) cout << "Close";
  if (a == 0 && b == 1 && c == 0) cout << "Close";
  if (a == 1 && b == 1 && c == 0) cout << "Open";
  if (a == 0 && b == 0 && c == 1) cout << "Open";
  if (a == 0 && b == 0 && c == 0) cout << "Close";
  cout << endl;
  return 0;
}