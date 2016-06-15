#include <iostream>
using namespace std;

int main() {
  double a;
  while (cin >> a) {
    if (a <= 48)
      cout << "light fly";
    else if (a <= 51)
      cout << "fly";
    else if (a <= 54)
      cout << "bantam";
    else if (a <= 57)
      cout << "feather";
    else if (a <= 60)
      cout << "light";
    else if (a <= 64)
      cout << "light welter";
    else if (a <= 69)
      cout << "welter";
    else if (a <= 75)
      cout << "light middle";
    else if (a <= 81)
      cout << "middle";
    else if (a <= 91)
      cout << "light heavy";
    else
      cout << "heavy";
    cout << endl;
  }

  return 0;
}