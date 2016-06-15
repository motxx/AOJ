#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pii;
typedef pair<int, Pii> Piii;  // solved, penalty, team

int main() {
  int T, P, R;

  while (cin >> T >> P >> R && (T | P | R)) {
    int wa[100][100] = {{}};
    bool ac[100][100] = {{}};
    vector<Piii> data(T);

    for (int i = 0; i < T; i++) {
      data[i].second.second = -i;
    }
    for (int i = 0; i < R; i++) {
      int t, p, r;
      string mes;
      cin >> t >> p >> r >> mes;
      t--;
      p--;
      if (mes[0] == 'W') {
        wa[t][p]++;
      } else {
        if (!ac[t][p]) {
          ac[t][p] = true;
          data[t].first++;
          data[t].second.first -= wa[t][p] * 1200 + r;
        }
      }
    }
    sort(data.begin(), data.end(), greater<Piii>());
    int const N = data.size();
    for (int i = 0; i < N; i++) {
      cout << -data[i].second.second + 1 << " " << data[i].first << " "
           << -data[i].second.first << endl;
    }
  }

  return 0;
}