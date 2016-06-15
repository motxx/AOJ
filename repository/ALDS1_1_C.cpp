#include <stdio.h>

inline bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }

  return 1;
}

int main() {
  int N;
  scanf("%d", &N);

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int in;
    scanf("%d", &in);
    cnt += isPrime(in);
  }

  printf("%d\n", cnt);

  return 0;
}