#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N), minVec(N);

  int ans = INT_MIN / 2;

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    if (!i) {
      minVec[i] = vec[i];
    } else {
      ans = max(ans, vec[i] - minVec[i - 1]);
      minVec[i] = min(minVec[i - 1], vec[i]);
    }
  }

  cout << ans << endl;

  return 0;
}