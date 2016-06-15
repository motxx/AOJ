#include <iostream>

using namespace std;

int main() {
  int K;
  while (cin >> K && K) {
    int cs = 0;
    for (int i = 0; i < K * (K - 1) / 2; i++) {
      int c;
      cin >> c;
      cs += c;
    }
    cout << cs / (K - 1) << endl;
  }
  return 0;
}