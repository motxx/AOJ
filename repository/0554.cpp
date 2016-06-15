#include <iostream>

using namespace std;

int main(void) {
  int t1, t2, t3, t4, tt;
  int x, y;

  cin >> t1 >> t2 >> t3 >> t4;

  tt = t1 + t2 + t3 + t4;

  cout << tt / 60 << endl << tt - (tt / 60) * 60 << endl;

  return 0;
}