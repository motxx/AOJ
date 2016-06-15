#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

int P;
string line;
string::iterator iter;

void init() {
  // global init
  line.clear();
}

ll mod_pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % P, n / 2);
  if (n & 1) res = res * x % P;
  return res;
}

void consume(char expected) {
  if (*iter == expected) {
    iter++;
  } else {
    cout << "Failed...\n";
    while (iter == line.end()) {
      cout << *iter;
    }
    cout << endl;

    assert(false);
  }
}

bool ifconsume(char expected) {
  if (*iter == expected) {
    consume(expected);
    return true;
  }
  return false;
}

ll expression();
ll term();
ll factor();

ll factor() {
  if (ifconsume('(')) {
    ll exp = expression();
    consume(')');
    return exp;
  } else {
    ll num = 0;
    while (isdigit(*iter)) {
      num *= 10;
      num += (*iter) - '0';
      consume(*iter);
    }
    return num;
  }
}

ll term() {
  ll factor1 = factor();
  while (1) {
    if (ifconsume('*')) {
      ll factor2 = factor();
      factor1 = (factor1 * factor2) % P;
    } else if (ifconsume('/')) {
      ll factor2 = factor();
      if (factor2 == 0) throw(0);
      factor1 = (factor1 * mod_pow(factor2, P - 2)) % P;
    } else {
      break;
    }
  }
  return factor1;
}

ll expression() {
  ll term1 = term();

  while (1) {
    if (ifconsume('+')) {
      ll term2 = term();
      term1 = (term1 + term2) % P;
    } else if (ifconsume('-')) {
      ll term2 = term();
      term1 += P;
      term1 = (term1 - term2) % P;
    } else {
      break;
    }
  }

  return term1;
}

int main() {
  string str;
  while (getline(cin, str)) {
    init();

    stringstream ss(str);
    ss >> P;
    if (P == 0) break;

    int sz = str.size();
    rep(i, sz) {
      if (str[i] == ':') {
        str = str.substr(i + 1);
        break;
      }
    }
    sz = str.size();

    rep(i, sz) {
      if (str[i] != ' ') {
        line.push_back(str[i]);
      }
    }

    iter = line.begin();
    try {
      int r = expression();
      cout << line << " = " << r << " (mod " << P << ")\n";
    } catch (...) {
      cout << "NG\n";
    }
  }

  return 0;
}