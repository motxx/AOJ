#include <bitset>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string a[128];

void init() {
  a[' '] = "101";
  a['\''] = "000000";
  a[','] = "000011";
  a['-'] = "10010001";
  a['.'] = "010001";
  a['?'] = "000001";
  a['A'] = "100101";
  a['B'] = "10011010";
  a['C'] = "0101";
  a['D'] = "0001";
  a['E'] = "110";
  a['F'] = "01001";
  a['G'] = "10011011";
  a['H'] = "010000";
  a['I'] = "0111";
  a['J'] = "10011000";
  a['K'] = "0110";
  a['L'] = "00100";
  a['M'] = "10011001";
  a['N'] = "10011110";
  a['O'] = "00101";
  a['P'] = "111";
  a['Q'] = "10011111";
  a['R'] = "1000";
  a['S'] = "00110";
  a['T'] = "00111";
  a['U'] = "10011100";
  a['V'] = "10011101";
  a['W'] = "000010";
  a['X'] = "10010010";
  a['Y'] = "10010011";
  a['Z'] = "10010000";
}

int main() {
  init();

  string s;
  while (getline(cin, s)) {
    stringstream ss;

    for (int i = 0; i < s.size(); i++) ss << a[s[i]];

    string str = ss.str();

    while (str.size() % 5) str += '0';

    for (int i = 0; i < str.size(); i += 5) {
      int b = bitset<5>(str.substr(i, 5)).to_ulong();
      if (b <= 25)
        cout << (char)(b + 'A');
      else if (b == 26)
        cout << ' ';
      else if (b == 27)
        cout << '.';
      else if (b == 28)
        cout << ',';
      else if (b == 29)
        cout << '-';
      else if (b == 30)
        cout << '\'';
      else
        cout << '?';
    }

    cout << endl;
  }

  return 0;
}