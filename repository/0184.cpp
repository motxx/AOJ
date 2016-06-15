#include <iostream>
main() {
  int n, x, i;
  while (std::cin >> n, n) {
    int dat[7] = {};
    for (i = 0; i<n; std::cin>> x, x = x / 10 > 6 ? 60 : x, dat[x / 10]++, i++)
      ;
    for (i = 0; i < 7; std::cout << dat[i] << '\n', i++)
      ;
  }
}