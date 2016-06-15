#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<string, int> P;

int main() {
  int n, t;
  vector<P> v;

  cin >> n >> t;

  int h1, m1, h2, m2;
  char c;
  string str;
  cin >> h1 >> c >> m1 >> str;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> h1 >> c >> m1 >> str;
    cin >> h2 >> c >> m2 >> str;
    int A = h2 * 60 + m2 - (h1 * 60 + m1);
    if (A >= t) {
      v.push_back(make_pair(str, A));
    }
  }

  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }

  return 0;
}