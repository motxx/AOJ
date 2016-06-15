#include <iostream>
using namespace std;

char getPartner(char ch) {
  string left = "()iw";
  string right = ")(iw";

  return left[right.find(ch)];
}

int main() {
  string str;
  int ret = 0;
  getline(cin, str);

  for (int i = 0; i <= (str.size() - 1) / 2; i++) {
    if (str[i] != getPartner(str[str.size() - 1 - i])) ret++;
  }

  cout << ret << endl;

  return 0;
}