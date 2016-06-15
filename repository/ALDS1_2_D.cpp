#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cnt;
int m;
vector<int> G;

void insertionSort(vector<int>& vec, int g) {
  for (int i = g; i < vec.size(); i++) {
    int v = vec[i];
    int j = i - g;
    while (j >= 0 && vec[j] > v) {
      vec[j + g] = vec[j];
      j = j - g;
      cnt++;
    }
    vec[j + g] = v;
  }
}

void shellSort(vector<int>& vec) {
  cnt = 0;

  G.push_back(1);
  for (int i = 1; 3 * G[i - 1] + 1 < vec.size() && G.size() <= 100; i++) {
    G.push_back(3 * G[i - 1] + 1);
  }
  m = G.size();
  reverse(G.begin(), G.end());

  for (int i = 0; i < m; i++) insertionSort(vec, G[i]);
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) cin >> vec[i];

  cnt = 0;
  shellSort(vec);

  cout << m << endl;
  for (int i = 0; i < m; i++) {
    if (i) cout << " ";
    cout << G[i];
  }
  cout << endl;
  cout << cnt << endl;

  for (int i = 0; i < N; i++) {
    cout << vec[i] << endl;
  }

  return 0;
}