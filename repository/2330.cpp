#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;

  int cnt = 0;
  while (n > 1) {
    if (n % 3 == 0)
      n /= 3;
    else
      n = n / 3 + 1;
    cnt++;
  }

  cout << cnt << endl;

  return 0;
}