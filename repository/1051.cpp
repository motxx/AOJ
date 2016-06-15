#include <iostream>
#define C std::cout <<
#define F(i, x) for (i = x; i < N; i++)
main() {
  for (int N; std::cin >> N && N;) {
    int A[N], i, j;
    F(i, 0) std::cin >> A[i];
    F(i, 0) {
      F(j, i + 1) if (A[j - 1] + 1 != A[j]) break;
      if (i) C " ";
      C A[i];
      if (j > i + 1) {
        C '-' << A[j - 1];
        i = j - 1;
      }
    }
    C '\n';
  }
}