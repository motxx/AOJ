#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-7)

double conv(double dosu) { return dosu * M_PI / 180.0; }

int main() {
  int M;

  while (cin >> M && M) {
    double sum = 0.0;
    double S = 0.0;
    for (int i = 0; i < M - 1; i++) {
      double arg;
      cin >> arg;
      S += sin(conv(arg));
      sum += arg;
    }
    S += sin(conv(360 - sum));

    int N;
    cin >> N;
    sum = 0;
    double T = 0.0;
    for (int i = 0; i < N - 1; i++) {
      double arg;
      cin >> arg;
      T += sin(conv(arg));
      sum += arg;
    }
    T += sin(conv(360 - sum));

    if (fabs(S - T) < EPS)
      cout << 0 << endl;
    else if (S > T)
      cout << 1 << endl;
    else if (S < T)
      cout << 2 << endl;
  }

  return 0;
}