#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> Pii;
int main() {
  int N, Q;
  cin >> N >> Q;
  static int memo[1000001];
  set<Pii> st;
  for (int q = 0; q < Q; q++) {
    int a, v;
    scanf("%d%d", &a, &v);
    st.erase(Pii(-memo[a], a));
    memo[a] += v;
    st.insert(Pii(-memo[a], a));
    printf("%d %d\n", st.begin()->second, -st.begin()->first);
  }
  return 0;
}