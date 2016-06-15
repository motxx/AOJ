#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int N;

  while (cin >> N && N) {
    int mx = 0;
    int mid;
    for (int i = 0; i < N; i++) {
      int id;
      cin >> id;
      int a, b;
      cin >> a >> b;
      if (mx < a + b) {
        mx = a + b;
        mid = id;
      }
    }
    cout << mid << " " << mx << endl;
  }

  return 0;
}