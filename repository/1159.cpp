#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, p;
  while (cin >> n >> p, (n | p)) {
    int c = p, curr = 0;
    vector<int> v(n);

    while (1) {
      if (c == 0) {
        c += v[curr];
        v[curr] = 0;
      } else {
        v[curr]++;
        c--;
        if (v[curr] == p) break;
      }
      curr = (curr + 1) % n;
    }
    cout << curr << endl;
  }

  return 0;
}