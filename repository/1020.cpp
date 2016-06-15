#include <cstdio>
#include <iostream>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ck(a) (0 <= (a) && (a) < 9)
int di[] = {-3, -1, 1, 3};
int main() {
  int n, s, t, b;
  char cs, ct, cb;
  while (scanf("%d", &n), n) {
    scanf(" %c %c %c", &cs, &ct, &cb);
    s = cs - 'A', t = ct - 'A', b = cb - 'A';
    double p[9] = {0};
    p[s] = 1;

    while (n--) {
      double q[9] = {0};
      rep(i, 9) rep(d, 4) {
        if (ck(i + di[d]) && !(i % 3 == 0 && di[d] == -1) &&
            !(i % 3 == 2 && di[d] == 1) && i + di[d] != b)
          q[i + di[d]] += p[i] / 4;
        else
          q[i] += p[i] / 4;
      }
      rep(i, 9) p[i] = q[i];
    }

    printf("%.8f\n", p[t]);
  }
  return 0;
}