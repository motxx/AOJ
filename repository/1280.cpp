#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int data[100];
inline int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
typedef pair<int, pair<int, int> > edges;

int const INF = 1 << 29;

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    edges es[M];
    rep(i, M) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--, b--;
      es[i] = make_pair(c, make_pair(a, b));
    }
    sort(es, es + M);
    int ret = INF;

    int st = 0;
    for (; M - st >= N - 1; st++) {
      memset(data, -1, sizeof data);
      int last = -1;
      int s = 0;
      REP(i, st, M) {
        int u = root(es[i].second.first), v = root(es[i].second.second);
        if (u != v) {
          data[u] += data[v];
          data[v] = u;
          last = i;
          s++;
          if (s == N - 1) {
            ret = min(ret, es[last].first - es[st].first);
            goto next;
          }
        }
      }
      break;
    next:;
    }
    printf("%d\n", ret < INF ? ret : -1);
  }

  return 0;
}