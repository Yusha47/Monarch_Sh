#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
bitset<N> f;
vector<int> primes;
void op_seive()
{
    int n = N - 9;

    f[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (!f[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                f[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!f[i])
        {
            primes.push_back(i);
        }
    }
  
}
int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    op_seive();
    
    int t;
    cin >> t;
    int cs=1;
    while (t--)
    {
        cout<<"Case "<<cs++<<": ";
        f[2]=1;
        int _n;
        cin >> _n;
        int ans = 0;
        for (auto x : primes)
        {
            if (_n - x >=0 )
            {
               // cout<<x<<" "<<_n-x<<endl;
                int b=_n-x;
                if ((f[_n - x]) && x<=b)
                {
                    ans++;
                }
            }
            else break;
        }
        cout << ans << endl;
    }

    return 0;
}
