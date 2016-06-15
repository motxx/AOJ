#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int n, a[100]; cin >> n;) {
    int sum = 0, p = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) sum += a[i], p += sum;
    cout << p << endl;
  }
}