#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

int const MOD = 1e9 + 7;

string line;
string::iterator iter;
inline void debug() {
  cout << "Remain: \"" << string(iter, line.end()) << '"' << endl;
}

void consume(char e) {
  if (*iter == e) {
    iter++;
  } else {
    assert(0);
  }
}

bool ifconsume(char e) {
  if (*iter == e) {
    consume(e);
    return 1;
  }
  return 0;
}

bool strcons(string s) {
  string::iterator is = s.begin();
  string::iterator tmpiter = iter;

  while (is != s.end() && tmpiter != line.end() && *is == *tmpiter) {
    tmpiter++;
    is++;
  }

  if (is == s.end()) {
    iter = tmpiter;
    return true;
  }
  return false;
}

ll get_num() {
  ll ret = 0;
  while (isdigit(*iter)) {
    ret *= 10;
    ret += (*iter) - '0';
    consume(*iter);
  }
  return ret;
}

ll expr();
ll term() {
  if (isdigit(*iter)) {
    return get_num();
  } else if (ifconsume('S')) {
    consume('<');
    ll r = expr();
    (r *= r) %= MOD;
    consume('>');
    return r;
  } else {
    debug();
    assert(0 && "term");
  }
}

ll expr() {
  ll t1 = term();
  while (strcons(">>")) {
    if (*iter != 'S' && !isdigit(*iter)) {
      iter -= 2;
      break;
    }
    int k = term();
    while (k--) {
      t1 >>= 1;
      if (t1 == 0) break;
    }
  }
  return t1;
}

int main() {
  for (string s; getline(cin, s);) {
    if (s == "#") break;
    line.clear();
    int sz = s.size();
    rep(i, sz) if (s[i] != ' ') { line.push_back(s[i]); }
    iter = line.begin();
    cout << expr() << endl;
  }

  return 0;
}