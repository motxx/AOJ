#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int const INF = 1 << 28;

int main() {
  int Tc;
  cin >> Tc;
  while (Tc--) {
    int H, W;
    cin >> H >> W;
    vector<vector<char> > a(H + 2, vector<char>(W + 2));
    vector<int> minX(128, INF), minY(128, INF);
    vector<int> maxX(128, -INF), maxY(128, -INF);
    vector<int> vec;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> a[i][j];
        if (!isalpha(a[i][j])) continue;
        int b = a[i][j];
        vec.push_back(b);
        maxX[b] = max(maxX[b], j);
        maxY[b] = max(maxY[b], i);
        minX[b] = min(minX[b], j);
        minY[b] = min(minY[b], i);
      }
    }
    if (vec.empty()) {
      cout << "SAFE" << endl;
      goto EXIT;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    do {
      bool good = true;
      vector<vector<char> > work(a);

      for (int I = 0; I < vec.size(); I++) {
        bool ok = true;
        for (int i = minY[vec[I]]; i <= maxY[vec[I]]; i++) {
          for (int j = minX[vec[I]]; j <= maxX[vec[I]]; j++) {
            if (work[i][j] == '#') {
            }
            if (work[i][j] != '#' && work[i][j] != (char)vec[I]) {
              ok = false;
              break;
            }
          }
          if (!ok) break;
        }  // for i
        if (!ok) {
          good = false;
          break;
        }
        for (int i = minY[vec[I]]; i <= maxY[vec[I]]; i++)
          for (int j = minX[vec[I]]; j <= maxX[vec[I]]; j++) {
            work[i][j] = '#';
          }
      }

      if (good) {
        cout << "SAFE" << endl;
        goto EXIT;
      }
    } while (next_permutation(vec.begin(), vec.end()));

    cout << "SUSPICIOUS" << endl;

  EXIT:;
  }

  return 0;
}