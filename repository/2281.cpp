#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int n, a[100], b[100], sabun, temp;
  string mes;
  char ch;

  while (1) {
    cin >> n;
    if (n == 0) break;

    cin >> mes;

    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      a[i]--;
      b[i]--;
    }

    // decode
    for (int i = n - 1; i >= 0; i--) {
      // susumeru
      sabun = (b[i] - a[i]) % 26;

      if (mes[a[i]] + sabun > 'z') {
        mes[a[i]] = 'a' + (mes[a[i]] + sabun - 1 - 'z');
      } else {
        mes[a[i]] += sabun;
      }

      if (mes[b[i]] + sabun > 'z') {
        mes[b[i]] = 'a' + (mes[b[i]] + sabun - 1 - 'z');
      } else {
        mes[b[i]] += sabun;
      }

      // change
      ch = mes[a[i]];
      mes[a[i]] = mes[b[i]];
      mes[b[i]] = ch;
    }

    cout << mes << endl;
  }
  return 0;
}