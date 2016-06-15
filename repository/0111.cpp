#include <iostream>
#include <map>
using namespace std;

string c2s(char ch) {
  if (ch == ' ') return "11010";
  if (ch == '.') return "11011";
  if (ch == ',') return "11100";
  if (ch == '-') return "11101";
  if (ch == '\'') return "11110";
  if (ch == '?') return "11111";

  int n = ch - 'A';
  string ret;
  for (int i = 4; i >= 0; i--) ret += n & (1 << i) ? '1' : '0';
  return ret;
}

map<string, char> sym;

void initsym() {
  sym["101"] = ' ';
  sym["000000"] = '\'';
  sym["000011"] = ',';
  sym["10010001"] = '-';
  sym["010001"] = '.';
  sym["000001"] = '?';
  sym["100101"] = 'A';
  sym["10011010"] = 'B';
  sym["0101"] = 'C';
  sym["0001"] = 'D';
  sym["110"] = 'E';
  sym["01001"] = 'F';
  sym["10011011"] = 'G';
  sym["010000"] = 'H';
  sym["0111"] = 'I';
  sym["10011000"] = 'J';
  sym["0110"] = 'K';
  sym["00100"] = 'L';
  sym["10011001"] = 'M';
  sym["10011110"] = 'N';
  sym["00101"] = 'O';
  sym["111"] = 'P';
  sym["10011111"] = 'Q';
  sym["1000"] = 'R';
  sym["00110"] = 'S';
  sym["00111"] = 'T';
  sym["10011100"] = 'U';
  sym["10011101"] = 'V';
  sym["000010"] = 'W';
  sym["10010010"] = 'X';
  sym["10010011"] = 'Y';
  sym["10010000"] = 'Z';
}

int main() {
  initsym();

  string s, str, res, temp;
  while (getline(cin, s)) {
    str = res = temp = "";
    for (unsigned i = 0; i < s.size(); i++) str += c2s(s[i]);
    for (unsigned i = 0; i < str.size(); i++) {
      temp += str[i];
      if (sym.count(temp)) res += sym[temp], temp = "";
    }
    cout << res << endl;
  }
  return 0;
}