#include <iostream>
using namespace std;
int main() {
  char op;
  int a, b;

  cin >> a;
  while (cin >> op) {
    if (op == '=') {
      cout << a << endl;
      break;
    }
    if (op == '+') {
      cin >> b;
      a += b;
    }
    if (op == '-') {
      cin >> b;
      a -= b;
    }
    if (op == '*') {
      cin >> b;
      a *= b;
    }
    if (op == '/') {
      cin >> b;
      a /= b;
    }
  }

  return 0;
}