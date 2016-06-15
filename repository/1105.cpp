#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a, b;

  while (cin >> n >> a >> b && (n | a | b)) {
    vector<bool> cantCount(n + 1, 0);

    for (int i = 0; i <= n; i++) {
      cantCount[i] = true;
    }

    for (int i = 0; i < b; i++)
      for (int can = a * i; can <= n; can += b) cantCount[can] = false;

    int sum = 0;
    for (int i = 1; i <= n; i++) sum += cantCount[i];

    cout << sum << endl;
  }

  return 0;
}