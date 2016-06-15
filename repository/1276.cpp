#include <iostream>
int p(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
main() {
  int n;
  while (std::cin >> n, n) {
    int a = 0;
    for (int s = -1; s < 2; s += 2)
      for (int i = 0; !p(n + i * s); i++, a++)
        ;
    std::cout << a << '\n';
  }
}