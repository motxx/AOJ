#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int par[MAX];
int rank[MAX];

void init_union_find() {
  for (int i = 0; i < MAX; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  }

  return par[x] = find(par[x]);
}

bool same(int x, int y) { return find(x) == find(y); }

void unite(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y) return;

  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
}

int main() {
  int n, q;
  int com, x, y;

  init_union_find();
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> com >> x >> y;
    if (com == 0)
      unite(x, y);
    else {
      cout << same(x, y) << endl;
    }
  }

  return 0;
}