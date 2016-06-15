#include <iostream>
#include <string>
using namespace std;

int main() {
  double l[10];
  char c;

  while (cin >> l[0] >> c) {
    // 区間全体を1に変換
    int sum = l[0];
    for (int i = 1; i < 10; i++) cin >> l[i] >> c, sum += l[i];
    for (int i = 0; i < 10; i++) l[i] = l[i] / sum;

    // 速さの和を1に変換
    double a, b;
    double left;
    cin >> a >> c >> b;
    left = a / (a + b);

    int t = 0;
    double L = 0.0;
    while (L < left) {
      L += l[t++];
    }
    cout << t << endl;
  }

  return 0;
}