#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string str[1000];
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }

  for (int i = 1; i < n; i++) {
    string temp;

    if (str[i] < str[0]) {
      temp = str[0];
      str[0] = str[i];
      str[i] = temp;
    }
  }

  cout << str[0] << endl;
  return 0;
}