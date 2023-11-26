#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

const int DEBUGGER = 1;

#define MAX 10000
#define mp make_pair
#define pb push_back

#define II ({ ll TEMP; cin>>TEMP; TEMP; })
#define SI ({ string TEMP; cin>>TEMP; TEMP; })
#define AI(a) ({ int n=sizeof(a)/sizeof(a[0]); rep(I,0,n)a[I]=II; })
#define AO(a) ({ int n=sizeof(a)/sizeof(a[0]); rep(I,0,n){cout<<(I?" ":"")<<a[I];} if(DEBUGGER)cout<<endl;else cout<<'\n'; })
#define VI(v) ({ rep(I, 0, v.size()) v[I] = II; })
#define VO(v) ({ rep(I,0,v.size()){cout<<(I?" ":"")<<v[I];} if(DEBUGGER)cout<<endl;else cout<<'\n'; })
#define dbg(a) ({ if(DEBUGGER)cout<<#a<<" = "<<a<<endl; })
#define outa(a) ({ if(DEBUGGER)dbg(a); else cout<<a<<'\n'; })

#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
#define repSe(i, st, end) for (int i = st; i < end; i++)
#define repS0(i, st, end) for (int i = st; i > 0; i--)
#define SET(a) memset(a, -1, sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define endl '\n'
#define MOD 1000000007
#define MX 105
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 1e9 + 7;
#define all(v) v.begin(), v.end()
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

bool check(ll x, ll y, ll h, ll w)
{
    if (x < 1 || x > h || y < 1 || y > w)
    {
        return false;
    }
    else
        return true;
}

ll sum(ll n1)
{
    return (n1 * (n1 + 1)) / 2;
}

void solve()
{
    dbg(1);
    ll n = II;

    vector<string> odd;
    vector<string> even;
    ll check[9999999];
    ll ans = 0;

    rep(i, 0, n)
    {
        string s;
        cin >> s;

        if (s.length() % 2 != 0)
        {
            odd.pb(s);
        }
        else
            even.pb(s);
    }

   dbg(1);
    for (int i=0;i<odd.size();i++)
    {
           string s=odd[i];
             ll sum_digit = 0;
        for (int i = 0; i < s.length(); i++)
        {
            s += s[i] - '0';
        }
        check[sum_digit]++;
    }
    for (int i=0;i<even.size();i++)
    {

       string s=even[i];
        ll sum_digit = 0;
        for (int i = 0; i < s.length(); i++)
        {
            s += s[i] - '0';
        }
        check[sum_digit]++;
    }
   for (int i=0;i<odd.size();i++)
    {
           string s=odd[i];
        ll left = 0;
        ll right = 0;
        ll left2 = 0;
        ll right2 = 0;
        ll sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            left += s[i] - '0';
        }
        for (int i = n / 2 + 1; i < n; i++)
        {
            right += s[i] - '0';
        }
        ll needL = abs(left - right);
        for (int i = 0; i < n / 2 + 1; i++)
        {
            left2 += s[i] - '0';
        }
        for (int i = n / 2 + 2; i < n; i++)
        {
            right2 += s[i] - '0';
        }
        ll needR = abs(left2 - right2);
        if (check[needL] >= 0)
        {
            ans += check[needL];
        }
    }
 for (int i=0;i<even.size();i++)
    {

       string s=even[i];
        ll sum_digit = 0;
        for (int i = 0; i < s.length(); i++)
        {
            s += s[i] - '0';
        }
        if (check[sum_digit] >= 0)
        {
            ans += 2;
        }
    }
    cout << ans << endl;
 }

int main()
{
    // FAST;

#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    // freopen("input.txt", "r", stdin);
    //
    //    // Printing the Output to output.txt file
    // freopen("output.txt", "w", stdout);
    //
#endif

    ll t = 1;
    

    while (t--)
    {

        solve();
    }
    return 0;
}

// cerr << "\n\n\n"
//      << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
