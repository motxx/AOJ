#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int main() {
  int N, M;
  cin >> N >> M;
  vector<PII> vec(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    vec[i] = make_pair(a, b);
  }

  int lim_a = 1;
  int ans = 0;
  int const size = vec.size();
  int ok = 0;
  for (int i = 0; i < size; i++) {
    int mx = 0;
    for (int j = 0; j < size; j++) {
      if (vec[j].first <= lim_a) {
        if (mx <= vec[j].second && lim_a <= vec[j].second) {
          mx = vec[j].second;
        }
      }
    }
    ans++;
    if (mx >= N) {
      ok = 1;
      break;
    }
    lim_a = mx + 1;
  }

  if (ok) {
    cout << ans << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}