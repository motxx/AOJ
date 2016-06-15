#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) {
      double a, b, c;
      cin >> a >> b >> c;
      string r;
      if (a == 100.0 || b == 100.0 || c == 100.0)
        r = "A";
      else if ((a + b) / 2 >= 90.0)
        r = "A";
      else if ((a + b + c) / 3 >= 80.0)
        r = "A";
      else if ((a + b + c) / 3 >= 70.0)
        r = "B";
      else if ((a + b + c) / 3 >= 50.0 && (a >= 80.0 || b >= 80.0))
        r = "B";
      else
        r = "C";
      cout << r << endl;
    }
  }

  return 0;
}