#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}
template <class T>
ostream& operator<<(ostream& ost, vector<T> const& v) {
  ost << "[";
  rep(i, v.size()) {
    if (i) ost << ", ";
    ost << v[i];
  }
  ost << "]";
  return ost;
}

namespace parser {

typedef string::const_iterator Iter;
Iter __begin, __end;
Iter __it;

void remain_dump() {
  cout << "Remain: '" << string(__it, __end) << "'" << endl;
}

void init_iterator(Iter begin, Iter end) {
  __begin = begin;
  __end = end;
  __it = begin;
}

void consume(char expected) {
  assert(__end != __it);
  if (*__it != expected) {
    remain_dump();
    assert(false);
  }
  __it++;
}

bool consume_if(char expected) {
  if (*__it != expected) return false;
  consume(expected);
  return true;
}

void unread() {
  assert(__it != __begin);
  __it--;
}

bool eof() { return __it == __end; }

void append(int& tar, char add) {
  tar *= 10;
  tar += add - '0';
}
void append(string& tar, char add) { tar += add; }

enum readable { alphabetical = 1 << 0, integer = 1 << 1 };
enum class lexstat { no_stat = -1, read_eof, success };

lexstat lstat = lexstat::no_stat;

template <class return_type>
return_type lex(readable rd, vector<char> const& skipper = {},
                vector<char> const& excepts = {}) {
  auto can_go = [&](char c) {
    if (find(skipper.begin(), skipper.end(), c) != skipper.end()) return false;
    if (find(excepts.begin(), excepts.end(), c) != excepts.end()) return true;
    if ((rd & alphabetical) && isalpha(c)) return true;
    if ((rd & integer) && isdigit(c)) return true;
    return false;
  };

  if (!can_go(*__it)) {
    lstat = lexstat::read_eof;
    return return_type{};
  }

  return_type ret{};
  while (can_go(*__it)) append(ret, *__it), consume(*__it);

  lstat = lexstat::success;

  return ret;
}

void lex_f(string const& force) {
  for (auto c : force) consume(c);
}

void lex_f(int force) { lex_f(to_string(force)); }

template <class return_type>
vector<return_type> lex_stream(readable rd, vector<char> const& skipper,
                               vector<char> const& excepts = {}) {
  vector<return_type> ret;
  while (1) {
    auto r = lex<return_type>(rd, skipper, excepts);
    if (lstat == lexstat::read_eof) break;
    ret.push_back(r);
    if (find(skipper.begin(), skipper.end(), *__it) != skipper.end()) {
      consume(*__it);
    }
  }
  return ret;
}

bool look_ahead(string const& expected) {
  int n = expected.size();
  int i = 0;
  while (i < n) {
    if (!consume_if(expected[i])) break;
    i++;
  }

  if (i == n) {
    while (i--) unread();
    return true;
  }

  while (i--) unread();
  return false;
}
}
using namespace parser;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef long long ll;
int const inf = 1 << 29;

struct xml {
  string tag;
  vector<int> prop;
  vector<shared_ptr<xml>> children;
};

shared_ptr<xml> parse(shared_ptr<xml>& p) {
  while (!eof()) {
    if (look_ahead("</")) {
      lex_f("</" + p->tag + ">");
      return p;
    } else if (look_ahead("<")) {
      auto c = make_shared<xml>();
      c->tag = lex<string>(alphabetical, {}, {'<', '>'});
      c->tag = c->tag.substr(1, c->tag.size() - 2);
      c->prop = lex_stream<int>(integer, {','});
      p->children.push_back(c);
      parse(c);
    }
  }
  return p;
}

shared_ptr<const xml> parse(Iter begin, Iter end) {
  init_iterator(begin, end);
  auto p = make_shared<xml>();
  p->tag = "OUT OF MAIN PANEL";
  return parse(p);
}

pair<string, int> dfs(shared_ptr<const xml> const& p, int x, int y) {
  for (auto&& c : p->children)
    if (c->prop[0] <= x && c->prop[1] <= y && x <= c->prop[2] &&
        y <= c->prop[3])
      return dfs(c, x, y);

  return {p->tag, p->children.size()};
}

int main() {
  for (int T; cin >> T;) {
    string xml_str;
    cin >> xml_str;
    auto root = parse(xml_str.begin(), xml_str.end());
    while (T--) {
      int x, y;
      cin >> x >> y;
      auto r = dfs(root, x, y);
      cout << r.first << " " << r.second << endl;
    }
  }
  return 0;
}