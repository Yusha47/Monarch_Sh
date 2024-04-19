#include <bits/stdc++.h>
using namespace std;
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
bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void solve()
{
    ll n = II, k = II;
    vector<ll> v(n);
    vector<ll> v2(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll temp = II;
        temp = abs(temp - 0LL);
        v2[i] = temp;
    }
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i)
    {

        vec.push_back({v[i], v2[i]});
    }
    // sort(vec.begin(), vec.end(), sortBySecond);
    //   for (int i=0;i<n;i++) {
    //     cout << "(" << v[i] << ", " << v2[i] << ") ";
    // }

    ll turn = 1;
    // outa(k);
    ll temp = k;
    for (int i = 0; i < n; i++)
    {
        // outa(temp);
        // outa(turn);
        outa(turn);
        cout<<v2[i]<<endl;
        if(i!=0)v2[i]=abs(v2-turn+1);
        if (temp > 0)
        {
            ll temp2 = v[i];

            v[i] -= min(temp, v[i]);
            temp -= min(temp, temp2);
            
        }
        cout << v[i] << " " << v2[i] - turn + 1 << endl;
        if (v2[i] - turn + 1 < 0)
        {
            cout << "NO1" << endl;
            return;
        }
        if (v[i] != 0)
        {
            ll need = ceil(v[i] / k);
            turn += need;
            outa(v2[i]);
            
            outa(v2[i] - turn + 1);
            if (v2[i] - turn + 1 <0)
            {
                cout << "NO" << endl;
                return;
            }
        }

    

        if (temp <= 0)
        {
            temp = k;
            turn++;
        }

        // outa(temp);
        // outa(turn);
    }
    cout << "YES" << endl;
}
int main()
{
    // FAST;

#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    // freopen("F:\GIT\input.txt", "r", stdin);

    // Printing the Output to output.txt file
    // freopen("F:\GIT\output.txt", "w", stdout);
    //
#endif

    ll t = 1;
    cin >> t;

    while (t--)
    {

        solve();
    }
    return 0;
}

// cerr << "\n\n\n"
//      << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
