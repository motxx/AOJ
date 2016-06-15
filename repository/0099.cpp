#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, q, a, v;
  priority_queue<pair<int, int> > pq;

  cin >> n >> q;
  vector<int> x(n + 1, 0);
  for (int i = 0; i < q; i++) {
    cin >> a >> v;
    x[a] += v;
    pq.push(make_pair(x[a], -a));
    for (;;) {
      int b = -pq.top().second;
      int w = pq.top().first;
      if (x[b] == w) {
        cout << b << " " << w << endl;
        break;
      }
      pq.pop();
    }
  }

  return 0;
}