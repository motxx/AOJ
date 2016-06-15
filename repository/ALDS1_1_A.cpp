#include <iostream>
#include <vector>

using namespace std;

void output(const vector<int>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    if (i) cout << " ";
    cout << vec[i];
  }
  cout << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  }

  output(vec);

  for (int j = 1; j < N; j++) {
    int key = vec[j];
    int i;
    for (i = j - 1; i >= 0 && key < vec[i]; i--) {
      vec[i + 1] = vec[i];
    }
    vec[i + 1] = key;
    output(vec);
  }

  return 0;
}