#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 100

int main() {
  while (1) {
    int a = -1, b;
    int V = 0;
    int edge[MAX] = {};
    while (cin >> a >> b && (a + b)) {
      V = max(V, max(a, b));
      a--, b--;
      edge[a]++, edge[b]++;
    }

    if (a == -1) break;

    if (edge[0] & 1 || edge[1] & 1) {
      for (int i = 2; i < V; i++)
        if (edge[i] % 2 == 1) goto NG;
      cout << "OK" << endl;
      goto Fin;
    }
  NG:
    cout << "NG" << endl;
  Fin:;
  }

  return 0;
}