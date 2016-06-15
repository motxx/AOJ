#include <iostream>
using namespace std;

int main() {
  const string list[10] = {"0111111", "0000110", "1011011", "1001111",
                           "1100110", "1101101", "1111101", "0100111",
                           "1111111", "1101111"};
  int M[10] = {};
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 7; j++) M[i] += (list[i][j] - '0') << j;

  int N;
  while (cin >> N && (N != -1)) {
    int S = 0;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      S ^= M[x];
      for (int j = 0; j < 7; j++) {
        cout << (S >> j & 1);
      }
      S = M[x];
      cout << endl;
    }
  }
  return 0;
}