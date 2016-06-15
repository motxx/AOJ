#include <bits/stdc++.h>

using namespace std;

typedef complex<double> P;

#define EPS (1e-7)

double dot(P const& a, P const& b) { return real(conj(a) * b); }

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

bool is_parallel(P const& a1, P const& a2, P const& b1, P const& b2) {
  return abs(cross(a2 - a1, b2 - b1)) < EPS;
}

bool is_orthogonal(P const& a1, P const& a2, P const& b1, P const& b2) {
  return abs(dot(a2 - a1, b2 - b1)) < EPS;
}

int main() {
  int q;
  cin >> q;
  for (; q--;) {
    P a1, a2, b1, b2;
    cin >> a1.real() >> a1.imag() >> a2.real() >> a2.imag();
    cin >> b1.real() >> b1.imag() >> b2.real() >> b2.imag();
    if (is_parallel(a1, a2, b1, b2)) {
      cout << 2 << endl;
    } else if (is_orthogonal(a1, a2, b1, b2)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}