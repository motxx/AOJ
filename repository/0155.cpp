#include <cmath>
#include <iostream>
using namespace std;

int x[1001], y[1001];
bool v[1001];
int p[1001];
double d[1001];
double edge[1001][1001];
int INF = (1 << 20);

void compute(int i, int j) {
  double temp = sqrt(((double)x[i] - x[j]) * (x[i] - x[j]) +
                     (y[i] - y[j]) * (y[i] - y[j]));
  if (temp <= 50) edge[i][j] = temp;
}

void dijkstra(int s, int g, int n) {
  int mn, hozon, b, cnt = 0;
  int a[1001];

  // init

  for (int i = 0; i <= 1000; i++) {
    v[i] = false;
    p[i] = 0;
    d[i] = INF;
    a[i] = 0;
  }

  // cout << "init: " << v[1] << " " << p[5] << " " << d[7] << " " << a[8] <<
  // endl;

  // cout << "dijkstra in" << endl;
  d[s] = 0;

  for (;;) {
    mn = INF;

    // tmp=hozon;
    for (int i = 1; i <= 1000; i++) {
      if (mn > d[i] && !v[i]) {
        mn = d[i];
        hozon = i;
      }
    }
    // via[hozon]=tmp;
    if (mn == INF) break;

    v[hozon] = true;

    for (int j = 1; j <= 1000; j++) {
      if (edge[hozon][j] == INF) continue;
      if (d[j] > d[hozon] + edge[hozon][j] && !v[j]) {
        // if(hozon==19)cout<<j<<" "<<d[j]<<" "<<edge[hozon][j]<<endl;
        d[j] = edge[hozon][j] + d[hozon];
        p[j] = hozon;
        // cout<<p[j]<<" "<<j<<endl;                    1657 2225 3872
      }
    }
  }
  if (d[g] == INF) {
    cout << "NA" << endl;
  } else {
    b = p[g];  // cout << "goal's p: " << p[g] << endl;   842 1800 900 3542
    while (1) {
      // cout << "test" << endl;
      if (b == s) {
        a[cnt++] = b;
        break;
      }
      a[cnt++] = b;
      b = p[b];
    }

    for (int i = cnt - 1; i >= 0; i--) {
      cout << a[i] << " ";
    }
    cout << g << endl;
  }
}

int main(void) {
  int s, g;
  int n;
  int b, m;

  while (1) {
    cin >> n;
    if (n == 0) break;

    for (int i = 1; i <= n; i++) {
      cin >> b;
      cin >> x[b] >> y[b];
    }

    for (int i = 1; i <= 1000; i++) {
      for (int j = 1; j <= 1000; j++) {
        edge[i][j] = INF;
        if (i != j) compute(i, j);
      }
    }

    cin >> m;  // cout << "m: " << m << endl;

    for (int i = 1; i <= m; i++) {
      cin >> s >> g;
      dijkstra(s, g, n);
    }
  }

  return 0;
}