#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c && (a | b | c)) {
    int N;
    cin >> N;
    vector<int> v(a + b + c + 1, 2);
    vector<int> I(N), J(N), K(N), R(N);
    for (int i = 0; i < N; i++) {
      cin >> I[i] >> J[i] >> K[i] >> R[i];
    }

    for (int i = 0; i < N; i++) {
      if (R[i]) {
        v[I[i]] = v[J[i]] = v[K[i]] = 1;
      }
    }
    for (int i = 0; i < N; i++) {
      if (!R[i]) {
        if (v[I[i]] == 1 && v[J[i]] == 1) v[K[i]] = 0;
        if (v[J[i]] == 1 && v[K[i]] == 1) v[I[i]] = 0;
        if (v[K[i]] == 1 && v[I[i]] == 1) v[J[i]] = 0;
      }
    }

    for (int i = 1; i <= a + b + c; i++) {
      cout << v[i] << endl;
    }
  }
  return 0;
}