#include <iostream>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  N--;
  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (N / 2 < x) x = N - x;
    if (N / 2 < y) y = N - y;
    cout << (min(x, y)) % 3 + 1 << endl;
  }
  return 0;
}