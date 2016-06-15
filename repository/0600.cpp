#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll const INF = 1LL << 60;

ll N;
ll sum[200001];
ll arr[100001];

ll midx;

bool C(ll d, ll S[], ll base) {
  ll p1 = lower_bound(S, S + N, d + base) - S;
  ll p2 = lower_bound(S, S + N, d + S[p1]) - S;
  if (N <= p2) return false;
  if (S[N - 1] - S[p2] >= d) {
    return true;
  }
  return false;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    sum[i] = arr[i];
    if (i) sum[i] += sum[i - 1];
  }
  for (int i = N; i < 2 * N; i++) {
    sum[i] = arr[i - N] + sum[i - 1];
  }

  ll ans = 0;
  for (midx = 0; midx < N; midx++) {
    ll lb = 0, ub = INF;
    while (ub - lb > 1) {
      ll mid = (lb + ub) / 2;
      ll c;
      if (midx > 0)
        c = sum[midx - 1];
      else
        c = 0;

      if (C(mid, sum + midx, c)) {
        lb = mid;
      } else {
        ub = mid;
      }
    }
    ans = max(ans, lb);
  }

  cout << ans << endl;

  return 0;
}