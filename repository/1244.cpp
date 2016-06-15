#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

map<string, int> atoms_map;
string::const_iterator iter;
string::const_iterator end;

void consume(char expected) {
  if (*iter == expected) {
    // cout << *iter;
    iter++;
    return;
  }
  assert(false);
}

bool ifconsume(char expected) {
  if (*iter == expected) {
    consume(expected);
    return true;
  } else {
    return false;
  }
}

string parse_atom() {
  bool first = 0;
  string work;
  for (; iter < end;) {
    if (!first && isupper(*iter)) {
      work += *iter;
      consume(*iter);
      first = 1;
    } else if (first && islower(*iter)) {
      work += *iter;
      consume(*iter);
    } else {
      break;
    }
  }
  return work;
}

int get_digits() {
  if (!isdigit(*iter)) return 1;

  int ret;
  ret = *iter - '0';
  consume(*iter);

  if (!isdigit(*iter)) {
    return ret;
  } else {
    ret *= 10;
    ret += *iter - '0';
    consume(*iter);
  }
  return ret;
}

int parse() {
  int ret = 0;
  for (; iter < end;) {
    if (ifconsume('(')) {
      // ( ... ) parsing
      int anum = parse();
      if (anum == -1) return -1;
      consume(')');

      // cout << "anum: " << anum << endl;

      anum *= get_digits();
      ret += anum;

      // cout << "mol: " <<  ret << endl;
    }

    else if (isalpha(*iter)) {
      // atom parsing
      string r = parse_atom();
      // cout << endl << "r: " << r << endl;

      map<string, int>::iterator it = atoms_map.find(r);
      if (it == atoms_map.end()) {
        return -1;
      }

      // cout << "number: " << it -> second << endl;

      int num = it->second;
      num *= get_digits();
      ret += num;
    } else if (*iter == ')') {
      return ret;
    } else {
      assert(false);
    }
  }

  return ret;
}

int main() {
  while (1) {
    string s;
    cin >> s;
    if (s == "END_OF_FIRST_PART") break;
    int x;
    cin >> x;
    atoms_map[s] = x;
  }
  while (1) {
    string s;
    cin >> s;
    if (s == "0") return 0;

    iter = s.begin(), end = s.end();

    int ans = parse();
    if (ans == -1) {
      cout << "UNKNOWN\n";
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}