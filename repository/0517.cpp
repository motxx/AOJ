#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  while (cin >> N >> K && (N | K)) {
    int cnt = 0;
    vector<int> v(K);
    for (int i = 0; i < K; i++) cin >> v[i];
    sort(v.begin(), v.end());
    bool zflag = false;
    if (v[0] == 0) zflag = true;
    int fst = 0, snd = 0;
    int len = 0;
    int zerocnt = 1;
    int prev = v[zflag];
    for (int i = 1 + zflag; i < K + 1; i++) {
      if (i < K && prev + 1 == v[i]) {
        snd = i;
        prev = v[i];
      } else if (i < K && zflag && zerocnt) {
        zerocnt--;
        fst--;
        i--;
        prev++;
      } else {
        len = max(len, snd - fst + 1);
        fst = i;
        if (zflag) {
          zerocnt = 1;
        }
        prev = v[i];
      }
    }
    cout << len << endl;
  }

  return 0;
}