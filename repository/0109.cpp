#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string query;
const char *p;

int exprs();

int factor() {
  char *e;
  int ret;

  if (*p == '(') {
    p++;
    ret = exprs();
    p++;
    return ret;
  }

  ret = strtol(p, &e, 10);
  // cout << "factor: " << ret << endl;
  p = e;
  // cout << *p << endl;

  return ret;
}

int term() {
  int ret = factor();

  for (;;) {
    if (*p == '*') {
      p++;
      ret *= factor();
    } else if (*p == '/') {
      p++;
      ret /= factor();
    } else {
      break;
    }
  }

  return ret;
}

int exprs() {
  int ret = term();
  for (;;) {
    if (*p == '+') {
      p++;
      ret += term();
    } else if (*p == '-') {
      p++;
      ret -= term();
    } else {
      break;
    }
  }

  return ret;
}

int main() {
  int n;

  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, query);
    query = query.substr(0, query.size() - 1);
    p = query.c_str();
    cout << exprs() << endl;
  }

  return 0;
}