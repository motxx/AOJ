#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    set<int> st;
    int cnt[5000] = {};
    for (int i = 0; i < n - 1; i++) {
      st.insert((i + 1) * (i + 1) % n);
    }

    int const size = st.size();

    vector<int> vec;
    set<int>::iterator it = st.begin();
    for (it; it != st.end(); it++) vec.push_back(*it);

    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        int temp = vec[i] - vec[j];
        if (temp < 0) {
          temp += n;
        }
        if (temp > (n - 1) / 2) {
          temp = n - temp;
        }
        cnt[temp]++;
      }
    }

    for (int i = 1; i <= (n - 1) / 2; i++) {
      cout << cnt[i] * 2 << endl;
    }
  }
  return 0;
}