#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int fee[7][7] = {
    {0, 300, 500, 600, 700, 1350, 1650},   {300, 0, 350, 450, 600, 1150, 1500},
    {500, 350, 0, 250, 400, 1000, 1350},   {600, 450, 250, 0, 250, 850, 1300},
    {700, 600, 400, 250, 0, 600, 1150},    {1350, 1150, 1000, 800, 600, 0, 500},
    {1650, 1500, 1350, 1300, 1150, 500, 0}};

int dist[7][7] = {{0, 6, 13, 18, 23, 43, 58}, {6, 0, 7, 12, 17, 37, 52},
                  {13, 7, 0, 5, 10, 30, 45},  {18, 12, 5, 0, 5, 25, 40},
                  {23, 17, 10, 5, 0, 20, 35}, {43, 37, 30, 25, 20, 0, 15},
                  {58, 52, 45, 40, 35, 15, 0}};

bool isHalf(int dst, int s, int t) {
  int const LIM_L = 17 * 60 + 30;
  int const LIM_U = 19 * 60 + 30;

  if (dst > 40) return false;

  if ((LIM_L <= s && s <= LIM_U) || (LIM_L <= t && t <= LIM_U)) return true;

  return false;
}

int main() {
  while (1) {
    int s, h, m;
    cin >> s >> h >> m;
    if (s == 0) break;
    int stime = h * 60 + m;

    int d;
    cin >> d >> h >> m;
    int dtime = h * 60 + m;

    int dst = dist[s - 1][d - 1];

    if (isHalf(dst, stime, dtime)) {
      cout << ceil(fee[s - 1][d - 1] / 50 / 2.0) * 50 << endl;
    } else
      cout << fee[s - 1][d - 1] << endl;
  }

  return 0;
}