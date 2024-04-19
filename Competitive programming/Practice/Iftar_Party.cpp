#include <bits/stdc++.h>
using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    int cs = 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        n -= k;
        
        vector<int> divisors;
        for (int i = 1;(long long) i * i <= n; i++) {
            if (n % i == 0) {
                if (k < i) {
                    divisors.push_back(i);
                }
                if (i != n / i && k < n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        sort(divisors.begin(), divisors.end());
        
         cout << "Case " << ++cs << ": ";
        
        if (divisors.empty()) {
            cout << "impossible\n";
        } else {
            for (auto x : divisors) {
                cout << x << ' ';
            }
              cout << '\n';
        }
        
      
    }
    
    return 0;
}

