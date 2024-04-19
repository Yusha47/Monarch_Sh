/**
 *    author:  tourist
 *    created: 08.04.2024 10:37:49
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto total = accumulate(a.begin(), a.end(), int64_t(0));
    if (total <= k) {
      cout << n << '\n';
      continue;
    }
    int64_t x = (k + 1) / 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] <= x) {
        x -= a[i];
        a[i] = 0;
        ans += 1;
      } else {
        break;
      }
    }
    x = k / 2;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] <= x) {
        x -= a[i];
        a[i] = 0;
        ans += 1;
      } else {
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
