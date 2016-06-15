#include <iostream>
#include <vector>

using namespace std;

vector<string> BubbleSort(vector<string> vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = vec.size() - 1; j > i; j--) {
      if (vec[j][1] - '0' < vec[j - 1][1] - '0') swap(vec[j], vec[j - 1]);
    }
  }

  return vec;
}

vector<string> SelectionSort(vector<string> vec) {
  for (int i = 0; i < vec.size(); i++) {
    int mini = i;
    for (int j = i; j < vec.size(); j++) {
      if (vec[j][1] - '0' < vec[mini][1] - '0') mini = j;
    }
    swap(vec[i], vec[mini]);
  }

  return vec;
}

int main() {
  int N;
  cin >> N;
  vector<string> raw(N);
  for (int i = 0; i < N; i++) cin >> raw[i];

  vector<string> bSorted = BubbleSort(raw);

  for (int i = 0; i < bSorted.size(); i++) {
    if (i) cout << " ";
    cout << bSorted[i];
  }
  cout << "\nStable" << endl;

  vector<string> selSorted = SelectionSort(raw);

  bool ok = true;
  for (int i = 0; i < bSorted.size(); i++)
    ok = ok && (bSorted[i] == selSorted[i]);

  for (int i = 0; i < selSorted.size(); i++) {
    if (i) cout << " ";
    cout << selSorted[i];
  }
  cout << endl;

  if (ok)
    cout << "Stable" << endl;
  else
    cout << "Not stable" << endl;

  return 0;
}