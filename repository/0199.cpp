#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define INF (1 << 29)

// math
#define Sq(x) ((x) * (x))

// container utility
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define EACH(it, c) \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

// rep
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FILE__ << endl;

// typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;

typedef long long ll;

// useful
#define FST first
#define SND second

#define CK(n, a, b) (a <= n && n < b)

// conversion
template <class T>
inline string toStr(T a) {
  ostringstream oss;
  oss << a;
  return oss.str();
}
inline int toInt(string s) { return atoi(s.c_str()); }

// prime
bool isPrime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}

// !!! set SSIEVVE_MAX_L number !!!
#define SSIEVE_MAX_L (1000001)
#define SSIEVE_MAX_SQRT_B ((int)sqrt(INT_MAX) + 1)

bool is_prime[SSIEVE_MAX_L];
vector<bool> is_prime_small(SSIEVE_MAX_SQRT_B);

void segment_sieve(ll a, ll b) {
  for (int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
  for (int i = 0; i < b - a; i++) is_prime[i] = true;

  if (a == 1) {
    is_prime[0] = false;
  }

  for (int i = 2; (ll)i * i < b; i++) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
        is_prime[j - a] = false;
    }
  }
}

int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//////////////////////////////////////////////////////////////

void Dump(vector<char> &chair) {
  cout << "--------------" << endl;
  EACH(i, chair) { cout << *i; }
  cout << endl;
  cout << "--------------" << endl;
}

void A(vector<char> &chair) {
  EACH(i, chair) {
    if (*i == '#') {
      *i = 'A';
      break;
    }
  }
}

void B(vector<char> &chair) {
  for (int i = chair.size() - 1; i > 0; i--) {
    if (chair[i] == '#' && chair[i - 1] != 'A') {
      if (i != chair.size() - 1 && chair[i + 1] == 'A') continue;
      chair[i] = 'B';
      return;
    }
  }

  EACH(i, chair) {
    if (*i == '#') {
      *i = 'B';
      return;
    }
  }
}

void C(vector<char> &chair) {
  bool check = 1;
  EACH(i, chair) check &= *i == '#';
  if (check) {
    int size = chair.size();
    if (size % 2) {
      chair[(size - 1) / 2] = 'C';
    } else {
      chair[size / 2] = 'C';
    }
    return;
  }

  for (int i = 0; i < chair.size() - 1; i++) {
    if (chair[i] != '#') {
      if (chair[i + 1] == '#') {
        chair[i + 1] = 'C';
        return;
      } else if (i && chair[i - 1] == '#') {
        chair[i - 1] = 'C';
        return;
      }
    }
  }
}

/*
int DCheck(vector<char> &chair, int pos) {

  bool noperson = true;
  int dist = 1;
  for(int i=pos-1; i>=0; i--) {
    if(chair[i] != '#') { noperson = false; break; }
    dist++;
  }
  if(noperson) { dist = pos+1; }

  noperson = true;
  int res = dist;
  dist = 1;
  for(int i=pos+1; i<chair.size(); i++) {
    if(chair[i] != '#') { noperson = false; break; }
    dist++;
  }
  if(noperson) { dist = pos+1; }

  return min(res, dist);
}
*/

void D(vector<char> &chair) {
  int const size = chair.size();
  VI arr(size);

  int fromR = 0;
  for (int i = size - 1; i >= 0; i--) {
    if (chair[i] == '#') {
      fromR++;
    } else {
      fromR = 0;
    }
    arr[i] = fromR;
  }

  int ret = 0;
  int fromL = 0;
  int pos = 0;
  for (int i = 0; i < size; i++) {
    if (chair[i] == '#') {
      fromL++;
    } else {
      fromL = 0;
    }

    if (!i || i == size - 1) {
      arr[i] = max(arr[i], fromL);
    } else {
      arr[i] = min(arr[i], fromL);
    }

    if (ret < arr[i]) {
      ret = arr[i], pos = i;
    }
  }

  chair[pos] = 'D';
}

void sit(char ch, vector<char> &chair) {
  switch (ch) {
    case 'A':
      A(chair);
      break;
    case 'B':
      B(chair);
      break;
    case 'C':
      C(chair);
      break;
    case 'D':
      D(chair);
      break;
  }
}

int main() {
  int N, M;

  while (cin >> N >> M && (N | M)) {
    vector<char> chair(N);

    fill(ALL(chair), '#');

    for (int i = 0; i < M; i++) {
      char ch;
      cin >> ch;
      sit(ch, chair);
      // Dump(chair);
    }

    EACH(i, chair) { cout << *i; }
    cout << endl;
  }

  return 0;
}