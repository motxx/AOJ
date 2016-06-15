#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    int h[N + 1];
    for (int i = 0; i < N + 1; i++) {
      cin >> h[i];
    }

    for (int i = 0; i < N + 1; i++) {
      vector<int> h2;
      for (int j = 0; j < N + 1; j++) {
        if (i == j) {
        } else
          h2.push_back(h[j]);
      }

      bool ok = true;
      const int diff = h2[1] - h2[0];
      for (int j = 0; j < N - 1; j++) {
        if (h2[j + 1] - h2[j] == diff) {
        } else {
          ok = false;
        }
      }
      if (ok) {
        cout << h[i] << endl;
        break;
      }
    }
  }
  return 0;
}