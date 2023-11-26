#include <bits/stdc++.h>
using namespace std;
#define dbg(a) cout << #a << " = " << a << endl

typedef long long ll;

const int MAX = 2e5 + 5;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<array<ll, 2>> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) a[i][1] = i;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll bp[n], j = 0;
    for (int i = n - x; i < n; i++) {
        bp[i] = b[j];
        j++;
    }
    for (int i = 0; i < n - x; i++) {
        bp[i] = b[j];
        j++;
    }

    ll ans[n];
    for (int i = 0; i < n; i++) {
        ans[a[i][1]] = bp[i];
    }

    int ct = 0;
    for (int i = 0; i < n; i++)
        ct += (a[i][0] > bp[i]);

    if (ct == x) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
