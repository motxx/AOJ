#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    vector<long> v, t;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    partial_sum(v.begin(), v.end(), back_inserter(t));
    long sum = 0;
    for (int i = 0; i < n - 1; i++) sum += t[i];
    cout << sum << endl;
  }
}