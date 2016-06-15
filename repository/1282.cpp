#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

string line;
int LineSize;

typedef pair<int, int> Pii;

map<Pii, int> memory;  // (id, idx) -> num
map<string, int> var_id;
set<string> variables;
map<int, int> var_size;
int id_size;

int find(int l, int r, char ch) {
  REP(i, l, r) {
    if (line[i] == ch) return i;
  }
  return -1;
}

bool valid_check(int id, int idx) {
  if (var_size[id] > idx) return true;
  return false;
}

/////////// get_num
int get_num(int st) {
  int ret = 0;
  REP(i, st, LineSize) {
    if (!isdigit(line[i])) break;
    ret *= 10;
    ret += line[i] - '0';
  }
  return ret;
}

//////////// get_idx
int parse(int, int);
int get_idx(int l, int r) {
  int kpos = find(l, r, '[');

  if (kpos == -1) assert(0);

  string str = string(line.begin() + l, line.begin() + kpos);

  if (isdigit(str[kpos + 1])) {
    return get_num(kpos + 1);
  } else {
    return parse(kpos + 1, r);
  }
}

int parse(int l, int r) {
  int kpos = find(l, r, '[');
  if (kpos == -1) {
    return get_num(l);
  }

  string vstr = string(line.begin() + l, line.begin() + kpos);
  int id = var_id[vstr], idx = get_idx(kpos, r);

  if (!valid_check(id, idx)) {
    throw(0);
  }

  map<Pii, int>::iterator iter = memory.find(Pii(id, idx));
  if (iter == memory.end()) {
    return -1;
  }
  return iter->second;
}

void dec_val(string s, int sz) {
  variables.insert(s);
  var_id[s] = id_size++;
  var_size[var_id[s]] = sz;
}

void interpret() {
  LineSize = line.size();

  int eqpos = find(0, LineSize, '=');

  if (eqpos == -1) {
    // declare
    int kpos = find(0, LineSize, '[');
    string s = string(line.begin(), line.begin() + kpos);
    int sz = get_num(kpos + 1);
    dec_val(s, sz);
  }

  else {
    // assign
    int kpos = find(0, LineSize, '[');
    string varstr = string(line.begin(), line.begin() + kpos);
    int id = var_id[varstr];
    int idx = parse(kpos + 1, eqpos);
    if (var_size[id] <= idx) {
      throw(0);
    }

    // rhs parse
    int rhs = parse(eqpos + 1, LineSize);
    if (rhs == -1) {
      throw(0);
    }
    memory[Pii(id, idx)] = rhs;
  }
}

void init() {
  variables.clear();
  memory.clear();
  var_id.clear();
  var_size.clear();
  id_size = 0;
}

bool get_next_line(string &line) {
  getline(cin, line);
  if (line == ".") return false;
  return true;
}

int main() {
  while (1) {
    init();

    getline(cin, line);
    if (line == ".") break;

    int line_cnt = 1;
    bool skip = 0;
    while (1) {
      if (!skip) {
        try {
          interpret();
        } catch (...) {
          cout << line_cnt << endl;
          skip = 1;
        }
      }

      if (!get_next_line(line)) {
        break;
      }
      line_cnt++;
    }
    if (!skip) {
      // no bug
      cout << 0 << endl;
    }
  }

  return 0;
}