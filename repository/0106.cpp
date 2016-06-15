#include <iostream>

using namespace std;

int getWeight(int a, int b, int c) { return a * 200 + b * 300 + c * 500; }

int getMoney(int a, int b, int c) {
  int res = 0;

  int a_ori = a % 5;
  int a_dis = a / 5 * 5;
  res += a_dis * 380 * 0.80 + a_ori * 380;

  int b_ori = b % 4;
  int b_dis = b / 4 * 4;
  res += b_dis * 550 * 0.85 + b_ori * 550;

  int c_ori = c % 3;
  int c_dis = c / 3 * 3;
  res += c_dis * 850 * 0.88 + c_ori * 850;

  return res;
}

int main() {
  int N;
  while (cin >> N && N) {
    int ans = (int)1e9;
    for (int i = 0; i < 30; i++)
      for (int j = 0; j < 30; j++)
        for (int k = 0; k < 30; k++)
          if (getWeight(i, j, k) == N) {
            ans = min(ans, getMoney(i, j, k));
          }

    cout << ans << endl;
  }

  return 0;
}