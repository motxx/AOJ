#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;

  while (cin >> n >> m, n || m) {
    vector<int> v;
    int cnt = 1;
    for (int i = 0; i < n; i++) v.push_back(i + 1);
    for (vector<int>::iterator it = v.begin(); v.size() > 1; cnt++) {
      if (it == v.end()) it = v.begin();
      if (cnt % m == 0)
        it = v.erase(it);
      else
        it++;
    }
    cout << v[0] << endl;
  }
  return 0;
}