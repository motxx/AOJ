#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

namespace solver {

string s;
typedef string::const_iterator Iter;
Iter it, end;

typedef pair<set<int>, char> pic;

void consume(char e) {
  assert(e == *it);
  it++;
}

bool isconsume(char e) {
  if (e == *it) {
    consume(e);
    return true;
  }
  return false;
}

int number() {
  int ret = 0;
  if (!isdigit(*it))
    return -1;
  while (isdigit(*it)) {
    ret *= 10;
    ret += *it - '0';
    it++;
  }
  return ret;
}

set<int> calc(set<int> const &n1, set<int> const &n2, char o) {
  set<int> ret;
  for (auto &&e : n1)
    for (auto &&u : n2) {
      if (o == '+')
        ret.insert(e + u);
      if (o == '-')
        ret.insert(e - u);
      if (o == '*')
        ret.insert(e * u);
      if (o == '/' && u != 0)
        ret.insert(e / u);
    }
  return ret;
}

void push_trans(queue<vector<pic>> &q, set<vector<pic>> &used,
                vector<pic> const &p, int i, set<int> const &n1,
                set<int> const &n2, char o, char nexto) {
  set<int> r = calc(n1, n2, o);
  auto nextp = p;
  nextp.erase(nextp.begin() + i);
  nextp.erase(nextp.begin() + i);
  nextp.insert(nextp.begin() + i, {r, nexto});
  if (used.count(nextp))
    return;
  used.insert(nextp);
  q.push(nextp);
}

set<int> expr() {
  vector<pic> v;
  while (1) {
    int num = number();
    set<int> nums;
    if (num == -1 && isconsume('(')) {
      nums = expr();
      consume(')');
    } else if (num == -1) {
      assert(0);
    } else {
      nums.insert(num);
    }

    if (isconsume('+'))
      v.push_back({nums, '+'});
    else if (isconsume('-'))
      v.push_back({nums, '-'});
    else if (isconsume('*'))
      v.push_back({nums, '*'});
    else if (isconsume('/'))
      v.push_back({nums, '/'});
    else {
      v.push_back({nums, '0'});
      break;
    }
  }

  queue<vector<pic>> q;
  q.push(v);
  set<vector<pic>> used;

  set<int> ret;

  for (; !q.empty(); q.pop()) {
    auto const &p = q.front();
    if (p.size() == 1) {
      for (auto &&e : p[0].first)
        ret.insert(e);
      continue;
    }
    assert(p.size());
    rep(i, p.size() - 1) push_trans(q, used, p, i, p[i].first, p[i + 1].first,
                                    p[i].second, p[i + 1].second);
  }

  return ret;
}

int solve() {
  it = s.begin(), end = s.end();
  return expr().size();
}
}

int main() {

  while (cin >> solver::s) {
    if (solver::s == "#")
      break;
    cout << solver::solve() << endl;
  }

  return 0;
}