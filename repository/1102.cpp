#include <bits/stdc++.h>

using namespace std;

string s;
string::const_iterator iter;
string::const_iterator enditer;

typedef complex<int> number;

void cons(char e) {
  if (*iter == e) {
    iter++;
  } else {
    assert(0);
  }
}

bool ifcons(char e) {
  if (*iter == e) {
    cons(e);
    return true;
  } else {
    return false;
  }
}

#define DEBUG                                                   \
  cout << "Remain string: \"" << string(iter, enditer) << endl; \
  assert(0);

inline void check_overflow(number x) {
  if (abs(real(x)) > 10000 || abs(imag(x)) > 10000) {
    throw(0);
  }
}

number fact();
number term();
number expr();

number fact() {
  number ret;
  int sign = +1;
  if (ifcons('-')) {
    sign = -1;
  }

  if (ifcons('(')) {
    ret = expr();
    cons(')');
  } else if (isdigit(*iter)) {
    int num = 0;
    bool out = 0;
    while (isdigit(*iter)) {
      num *= 10;
      num += (*iter++) - '0';
      if (num > 10000) out = 1, num = 0;
    }
    if (out) {
      throw(0);
    } else {
      ret = number(num, 0);
    }
  } else if (ifcons('i')) {
    ret = number(0, 1);
  } else {
    DEBUG;
  }

  return ret * number(sign, 0);
}

number term() {
  number ret = fact();

  for (;;) {
    if (ifcons('*')) {
      ret *= fact();
      check_overflow(ret);
    } else {
      break;
    }
  }
  return ret;
}

number expr() {
  number ret = term();

  for (;;) {
    if (ifcons('+')) {
      ret += term();
      check_overflow(ret);
    } else if (ifcons('-')) {
      ret -= term();
      check_overflow(ret);
    } else {
      break;
    }
  }
  return ret;
}

int main() {
  while (getline(cin, s)) {
    iter = s.begin();
    enditer = s.end();
    number r;
    try {
      r = expr();
    } catch (...) {
      cout << "overflow\n";
      continue;
    }
    if (abs(real(r)) <= 10000 && abs(imag(r)) <= 10000) {
      if (r == number(0, 0))
        cout << 0 << endl;
      else {
        bool f = 1;
        if (real(r) == 0) {
          f = 0;
        } else {
          cout << real(r);
        }
        if (imag(r) != 0) {
          if (f && imag(r) > 0) cout << "+";
          if (imag(r) < 0) cout << "-";
          cout << abs(imag(r));
          cout << "i";
        }
        cout << endl;
      }
    } else {
      cout << "overflow\n";
    }
  }

  return 0;
}