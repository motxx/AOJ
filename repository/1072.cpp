#include <iostream>
main() {
  for (int r, c; std::cin >> r >> c && r;)
    std::cout << (r * c % 2 ? "no" : "yes") << '\n';
}