#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
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

typedef long long ll;

typedef shared_ptr<struct tree> tree_ptr;

struct tree {
  string s;
  vector<tree_ptr> children;
  ll num = 1;
  tree() = default;
  tree(string s, ll num) : s(s), num(num) {}
};

ll read_k(string& s) {
  stringstream ss(s);
  int x;
  string t;
  ss >> x >> t;
  s = t;
  return x;
}

string read_s(string& s) {
  int n = s.size();
  string t;
  int last = -1;
  bool br = 0;
  rep(i, n) {
    last = i;
    if (!isalpha(s[i])) {
      br = 1;
      break;
    }
    t.push_back(s[i]);
  }
  if (br)
    s = s.substr(last);
  else
    s = "";
  return t;
}

void consume(string& s, char expected) {
  if (s[0] != expected) {
    cout << "Expected: " << expected << endl;
    cout << "Remain: " << s << endl;
    assert(0);
  }
  s = s.substr(1);
}

void dfs(string& s, tree_ptr curr) {
  for (; !s.empty();) {
    if (isdigit(s[0])) {
      ll ck = read_k(s);
      if (isalpha(s[0])) {
        auto c = make_shared<tree>();
        c->num = ck;
        c->s = read_s(s);
        curr->children.push_back(c);
      } else {
        consume(s, '(');
        auto c = make_shared<tree>();
        curr->children.push_back(c);
        c->num = ck;
        dfs(s, c);
        consume(s, ')');
      }
    } else {
      auto c = make_shared<tree>();
      c->s = read_s(s);
      c->num = 1;
      curr->children.push_back(c);
      if (!s.empty() && !isdigit(s[0])) {
        return;
      }
    }
  }
}

string ans;

void visit(tree_ptr curr) {
  if (ans.size() >= 1000001) {
    return;
  }
  rep(i, curr->num) {
    if (curr->children.empty()) {
      ans += curr->s;
      if (ans.size() >= 1000001) {
        return;
      }
    }

    rep(i, curr->children.size()) { visit(curr->children[i]); }
  }
}

char solve(string& s, int idx) {
  auto root = make_shared<tree>();
  dfs(s, root);
  ans.clear();
  visit(root);
  if (ans.size() <= idx) {
    return '0';
  }
  //  cout << ans << endl;cout << ans.size() << " / " << idx << endl;
  return ans[idx];
}

int main() {
  while (1) {
    string s;
    cin >> s;
    int idx;
    cin >> idx;
    if (s == "0" && idx == 0) {
      break;
    }
    cout << solve(s, idx) << endl;
  }

  return 0;
}