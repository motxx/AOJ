#include <bits/stdc++.h>
using namespace std;

map<string, bool> memo;

bool parse(string s) {
  if (memo.find(s) != memo.end()) return memo[s];
  if (s == "") return 1;
  int const size = s.size();
  if (s[0] != 'm' || s[size - 1] != 'w') return memo[s] = 0;

  bool ok = 0;
  for (int i = 1; i < size; i++) {
    if (s[i] == 'e') {
      if (parse(s.substr(1, i - 1)) && parse(s.substr(i + 1, size - i - 2)))
        return memo[s] = 1;
    }
  }
  return memo[s] = 0;
}

string checker(string s) { return parse(s) ? "Cat" : "Rabbit"; }

int main() {
  string s;
  cin >> s;

  cout << checker(s) << endl;

  return 0;
}
/*
以下は無駄なことしてて2秒くらいかかるコード
bool parse(string s) {
  if(memo.find(s) != memo.end()) return memo[s];
  if(s == "") return true;
  int const size = s.size();

  bool ok = 0;
  for(int i=1; i<size; i++) {
    if(s[i] == 'e') {
      string temp;
      string t = "m";
      if(i-1>=0) {
        if(parse(temp = s.substr(1, i-1))) t+=temp;
        else continue;
      }
      t += "e";
      if(size-i-2>=0) {
        if(parse(temp = s.substr(i+1, size-i-2))) t+=temp;
        else continue;
      }
      t +="w";
      ok |= s == t;
    }
  }
  return memo[s] = ok;
}
*/