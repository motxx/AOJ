#include <iostream>
using namespace std;

int main() {
  int y, m, d;

  while (cin >> y >> m >> d) {
    if (y < 1868 || y == 1868 && m < 9 || y == 1868 && m == 9 && d < 8)
      cout << "pre-meiji" << endl;
    else if (y < 1912 || y == 1912 && m < 7 || y == 1912 && m == 7 && d < 30)
      cout << "meiji " << y - 1868 + 1 << " " << m << " " << d << endl;
    else if (y < 1926 || y == 1926 && m < 12 || y == 1926 && m == 12 && d < 25)
      cout << "taisho " << y - 1912 + 1 << " " << m << " " << d << endl;
    else if (y < 1989 || y == 1989 && m == 1 && d < 8)
      cout << "showa " << y - 1926 + 1 << " " << m << " " << d << endl;
    else
      cout << "heisei " << y - 1989 + 1 << " " << m << " " << d << endl;
  }

  return 0;
}