
#include <iostream>
using namespace std;

int main() {
  int a;
  char cm;
  string b;
  int dat[128] = {};
  while (cin >> a >> cm >> b) {
    if (b == "AB") b = "D";
    dat[b[0]]++;
  }
  cout << dat['A'] << endl
       << dat['B'] << endl
       << dat['D'] << endl
       << dat['O'] << endl;

  return 0;
}