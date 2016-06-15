#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int n;
string s;
map<int, char> mp;

string::const_iterator iter, end_;
string ans;

void consume(char ex) {
  assert(ex == *iter);
  iter++;
}

bool consume_if(char ex) {
  if (ex == *iter) {
    consume(ex);
    return true;
  }
  return false;
}

void rec(deque<char>& res, int qcnt = 0) {
  int prog = 0;
  while (iter != end_) {
    if (isalpha(*iter)) {
      res.push_back(char((*iter - 'A' + prog) % 26 + 'A'));
      consume(*iter);
      prog = 0;
    } else if (consume_if('+')) {
      prog++;
    } else if (consume_if('-')) {
      prog--;
      if (prog < 0) prog = 25;
    } else if (consume_if('[')) {
      int pos = res.size();
      rec(res);
      assert(pos < (int)res.size());
      reverse(res.begin() + pos, res.end());
    } else if (consume_if(']')) {
      return;
    } else if (consume_if('?')) {
      prog = 0;
      res.push_back(mp[qcnt]);
      qcnt++;
    }
  }

  if (iter == end_) {
    string x;
    rep(i, res.size()) { x.push_back(res[i]); }
    ans = min(ans, x);
  }
}

int main() {
  while (1) {
    cin >> s;
    if (s == ".") break;
    ans = string(88, 'Z');

    n = s.size();
    vector<int> qs;
    rep(i, n) {
      if (s[i] == '?') {
        qs.push_back(i);
      }
    }

    rep(i, pow(26, qs.size())) {
      mp.clear();
      int k = i;
      rep(j, qs.size()) {
        mp[j] = char('A' + (k % 26));
        k /= 26;
      }
      iter = s.begin(), end_ = s.end();
      deque<char> d;
      rec(d);
    }
    cout << ans << endl;
  }

  return 0;
}