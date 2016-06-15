#include <iostream>
#include <vector>

#define bottom(v) v[v.size() - 1]

using namespace std;

int main() {
  int n, t;
  vector<int> v1, v2;
  cin >> n;

  while (n--) {
    bool isOk = true;
    for (int i = 0; i < 10; i++) {
      cin >> t;
      if (v1.empty() || bottom(v1) < t)
        v1.push_back(t);
      else if (v2.empty() || bottom(v2) < t)
        v2.push_back(t);
      else
        isOk = false;
    }
    cout << (isOk ? "YES" : "NO") << endl;
    v1.clear();
    v2.clear();
  }
  return 0;
}