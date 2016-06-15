#include <bits/stdc++.h>

using namespace std;

string str;
int pos, P, Q, R;

int formula() {
  pos++;
  if (str[pos] == '(') {
    int f = formula();
    pos++;
    if (str[pos] == '*') f = min(f, formula());
    if (str[pos] == '+') f = max(f, formula());
    pos++;
    return f;
  }
  if (str[pos] == '-') return 2 - formula();
  if (str[pos] == 'P') return P;
  if (str[pos] == 'Q') return Q;
  if (str[pos] == 'R') return R;
  if (isdigit(str[pos])) return str[pos] - '0';
}

int main() {
  while (cin >> str) {
    if (str == ".") return 0;
    int cnt = 0;
    for (P = 0; P <= 2; P++)
      for (Q = 0; Q <= 2; Q++)
        for (R = 0; R <= 2; R++) {
          pos = -1;
          cnt += formula() == 2;
        }
    cout << cnt << endl;
  }
  return 0;
}