#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

string s;
typedef long long ll;
typedef string::const_iterator Iter;
typedef set<ll>::const_iterator SIter;

Iter skip_par(Iter it) {
  it++;
  for (int cnt = 1;; it++) {
    if (*it == '(') cnt++;
    if (*it == ')') cnt--;
    if (cnt == 0) break;
  }
  return it;
}

bool number(Iter st, Iter ed, ll& ret) {
  ret = 0;
  for (Iter curr = st; curr != ed; curr++) {
    if (isdigit(*curr)) {
      ret *= 10;
      ret += (*curr) - '0';
    } else {
      return false;
    }
  }
  return true;
}

set<char> opes = {'+', '-', '*', '/'};

set<ll> exp(Iter st, Iter ed) {
  bool ok = false;
  if (*st == '(') {
    Iter ii = st;
    ii = skip_par(ii);
    if (ii == ed - 1) ok = true;
  }
  if (ok && *st == '(' && *(ed - 1) == ')') {
    return exp(st + 1, ed - 1);
  }
  {
    ll num;
    if (number(st, ed, num)) {
      return {num};
    }
  }
  set<ll> ret;
  for (Iter curr = st; curr != ed; curr++) {
    if (*curr == '(') {
      curr = skip_par(curr);
    } else if (opes.count(*curr)) {
      set<ll> l = exp(st, curr);
      set<ll> r = exp(curr + 1, ed);
      for (SIter i = l.begin(); i != l.end(); i++) {
        for (SIter j = r.begin(); j != r.end(); j++) {
          switch (*curr) {
            case '+':
              ret.insert(*i + *j);
              break;
            case '-':
              ret.insert(*i - *j);
              break;
            case '*':
              ret.insert(*i * *j);
              break;
            case '/':
              if (*j != 0) {
                ret.insert(*i / (*j));
              }
              break;
          }
        }
      }
    }
  }

  return ret;
}

int main() {
  for (int i = 0; i++, getline(cin, s);) {
    if (s == "#") {
      break;
    }
    Iter it = s.begin(), ed = s.end();
    cout << exp(it, ed).size() << endl;
  }

  return 0;
}