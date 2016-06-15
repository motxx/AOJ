#include <bits/stdc++.h>

using namespace std;

#define SEGTREE_MAX_N (1 << 17)

class SegmentTree {
 private:
  int size;
  vector<int> dat;

  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INT_MAX;

    if (a <= l && r <= b) return dat[k];
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return min(vl, vr);
  }

 public:
  SegmentTree(int n_) {
    size = 1;
    while (size < n_) size *= 2;
    dat.resize(2 * size - 1, INT_MAX);
  }

  void update(int k, int a) {
    k += size - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  // RangeMinimumQuery
  // input: [s, t)
  int find(int s, int t) { return query(s, t, 0, 0, size); }
};

int main() {
  int nn, q;
  int c;
  cin >> nn >> q;

  SegmentTree stree(nn);

  for (int i = 0; i < q; i++) {
    cin >> c;

    if (c) {
      int s, t;
      cin >> s >> t;
      cout << stree.find(s, t + 1) << endl;
    } else {
      int i, x;
      cin >> i >> x;
      stree.update(i, x);
    }
  }

  return 0;
}