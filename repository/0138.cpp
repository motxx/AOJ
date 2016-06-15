#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<double, int> PINT;

int main() {
  vector<PINT> v;
  double n1;
  int n2;

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 8; i++) {
      cin >> n2 >> n1;
      v.push_back(make_pair(n1, n2));
    }

    sort(v.begin() + j * 8, v.end());
    cout << v[j * 8].second << " " << v[j * 8].first << endl;
    v[j * 8].first = 10000000.0;
    cout << v[j * 8 + 1].second << " " << v[j * 8 + 1].first << endl;
    v[j * 8 + 1].first = 10000000.0;
  }

  sort(v.begin(), v.end());
  printf("%d %.2f\n", v[0].second, v[0].first);
  printf("%d %.2f\n", v[1].second, v[1].first);

  return 0;
}