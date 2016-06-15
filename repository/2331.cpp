#include <iostream>
using namespace std;

#define MAX 100002

int main() {
  int n;
  int a, b;
  int v[MAX] = {};

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v[a]++;
    v[b + 1]--;
  }

  int now = 0;
  int ans = 0;
  for (int i = 0; i < MAX; i++) {
    now += v[i];
    if (i <= now + 1) ans = i - 1;
  }

  cout << ans << endl;

  return 0;
}