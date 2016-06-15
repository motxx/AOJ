#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const char *p;

int solve() {
  int ret = 0;

  ++p;
  if (*p == '[') {
    vector<int> v;
    while (*p == '[') v.push_back(solve());
    sort(v.begin(), v.end());
    for (int i = v.size() / 2; i >= 0; i--) ret += v[i];
  } else {
    char *e;
    ret = strtol(p, &e, 10) / 2 + 1;
    p = e;
  }
  ++p;
  return ret;
}

int main() {
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    p = s.c_str();
    cout << solve() << endl;
  }
  return 0;
}