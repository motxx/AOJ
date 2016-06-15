#include <iostream>

using namespace std;

int main() {
  int n;
  int a, b, c, d;
  bool start = false;
  while (cin >> n, n) {
    if (start) cout << endl;
    start = true;
    int ans[4] = {};
    cin >> a >> b >> c >> d;
    int mn = (int)10e9;
    for (int i = 0; i <= a; i++)
      for (int j = 0; j <= b; j++)
        for (int k = 0; k <= c; k++)
          for (int l = 0; l <= d; l++) {
            const int all = a * 10 + b * 50 + c * 100 + d * 500;
            int temp = i * 10 + j * 50 + k * 100 + l * 500;
            if (temp - n >= 0) {
              int mom = temp - n;
              int D = mom / 500;
              mom -= D * 500;
              int C = mom / 100;
              mom -= C * 100;
              int B = mom / 50;
              mom -= B * 50;
              int A = mom / 10;
              int cand = A + B + C + D + a - i + b - j + c - k + d - l;

              if (cand < mn) {
                mn = cand;
                /*
                cout << "cand: " << cand << endl;
                cout << i << " " <<j << " " <<k<<" "<<l<<endl;
                */
                ans[0] = i;
                ans[1] = j;
                ans[2] = k;
                ans[3] = l;
              }
            }
          }
    if (ans[0]) cout << "10 " << ans[0] << endl;
    if (ans[1]) cout << "50 " << ans[1] << endl;
    if (ans[2]) cout << "100 " << ans[2] << endl;
    if (ans[3]) cout << "500 " << ans[3] << endl;
  }

  return 0;
}