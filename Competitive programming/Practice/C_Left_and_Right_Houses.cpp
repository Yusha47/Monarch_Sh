#include <bits/stdc++.h>
using namespace std;





void solve() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> pre(n);
    pre[0] = str[0] == '1';
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (str[i] == '1');
    }
    auto getSum = [&] (int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l - 1];
    };

    int ans = n;
    if (getSum(0, n - 1) >= (n + 1) / 2) {
        ans = 0;
    }

    for (int i = 0; i < n; i++) {
        int l1 = getSum(0, i);
        int l0 = i + 1 - l1;
        int r1 = getSum(i + 1, n - 1);
        int r0 = n - i - 1 - r1;

        if (l0 >= l1 && r1 >= r0) {
            if (abs(n - 2 * ans) > abs(n - 2 * (i + 1))) {
                ans = i + 1;
            }
        }
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        
        solve();
       
    }
    
    return 0;
}