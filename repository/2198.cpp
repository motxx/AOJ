#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<double, string> P;

int main() {
  int n;
  while (cin >> n && n) {
    vector<P> vec(n);
    string l;
    int p, a, b, c, d, e, f, s, m;
    for (int i = 0; i < n; i++) {
      cin >> l;
      cin >> p >> a >> b >> c >> d >> e >> f >> s >> m;
      vec[i] =
          make_pair(-(double)(f * s * m - p) / ((a + b + c + (d + e) * m)), l);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
      cout << vec[i].second << endl;
    }
    cout << "#\n";
  }

  return 0;
}