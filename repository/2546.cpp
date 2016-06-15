#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<deque<int> > cho;
  cho.resize(N);
  for (int i = 0; i < N; i++) {
    cho[i].resize(M);
    for (int j = 0; j < M; j++) {
      cin >> cho[i][j];
      if (i) cho[i][j] = 1 - cho[i][j];
    }
  }

  int all = 0;
  for (int i = 0; i < N; i++) {
    deque<int> work(cho[i]);
    int cnt = 0;
    for (int j = 0; j < M - 1; j++) {
      work[j + 1] = 1 - work[j + 1];
      cnt += work[j];
    }

    int mx = cnt;

    work = cho[i];
    cnt = 0;
    for (int j = M - 1; j > 0; j--) {
      work[j - 1] = 1 - work[j - 1];
      cnt += work[j];
    }

    mx = max(mx, cnt);

    work = cho[i];
    cnt = 0;
    while (!work.empty()) {
      if (work[0] == 1) {
        work.pop_front();
        cnt++;
        work[0] = 1 - work[0];
      } else if (work[work.size() - 1] == 1) {
        work.pop_back();
        cnt++;
        work[work.size() - 1] = 1 - work[work.size() - 1];
      } else {
        work.pop_front();
        work[0] = 1 - work[0];
      }
    }

    mx = max(mx, cnt);
    all += mx;
  }

  cout << all << endl;

  return 0;
}