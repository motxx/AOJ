#include <iostream>

using namespace std;

int main() {
  int N, K;
  while (cin >> N >> K && (N | K)) {
    int S[100];
    for (int i = 0; i < K; i++) {
      cin >> S[i];
    }
    int B[100][100];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < K; j++) {
        cin >> B[i][j];
      }
    }
    for (int i = 0; i < K; i++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        sum += B[j][i];
      }
      if (S[i] < sum) {
        cout << "No" << endl;
        goto EXIT;
      }
    }
    cout << "Yes" << endl;

  EXIT:;
  }

  return 0;
}