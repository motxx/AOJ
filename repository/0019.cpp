#include <iostream>
main() {
  long long n, i;
  std::cin >> n;
  for (i = n; --n;) i *= n;
  std::cout << i << "\n";
}