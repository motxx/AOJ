#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  char ch;
  int K, U, P, C;

  K = U = P = C;
  while (cin >> ch) {
    if (ch == 'K') K++;
    if (ch == 'U') U++;
    if (ch == 'P') P++;
    if (ch == 'C') C++;
  }

  cout << min(K, min(U, min(P, C))) << endl;

  return 0;
}