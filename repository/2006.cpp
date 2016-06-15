#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string mes[] = {".,!? ", "abc",  "def", "ghi", "jkl",
                "mno",   "pqrs", "tuv", "wxyz"};

int main() {
  int n;

  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int N = s.size();
    int pos = -1;
    int stock = -1;
    for (int i = 0; i < N; i++) {
      int button = s[i] - '0' - 1;
      if (button == -1) {
        if (stock != -1) cout << mes[stock][pos % (mes[stock].size())];
        stock = -1;
        pos = -1;
      } else {
        stock = button;
        pos++;
      }
    }
    cout << endl;
  }

  return 0;
}