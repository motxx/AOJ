#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    int x;
    cin >> x;
    stack<pair<int, int> > st;
    st.push(make_pair(1, x));
    for (int i = 0; i < N - 1; i++) {
      cin >> x;
      if (i % 2 == 0) {
        // even
        pair<int, int> p = st.top();
        if (p.second == x) {
          st.pop();
          st.push(make_pair(p.first + 1, x));
        } else {
          st.pop();
          pair<int, int> q;
          if (!st.empty()) {
            q = st.top();
            st.pop();
          }
          st.push(make_pair(p.first + q.first + 1, x));
        }
      } else {
        // odd
        pair<int, int> p = st.top();
        if (p.second == x) {
          st.pop();
          st.push(make_pair(p.first + 1, x));
        } else {
          st.push(make_pair(1, x));
        }
      }
    }

    int cnt = 0;
    for (; !st.empty();) {
      cnt += (st.top().second == 0) * st.top().first;
      st.pop();
    }
    cout << cnt << endl;
  }

  return 0;
}