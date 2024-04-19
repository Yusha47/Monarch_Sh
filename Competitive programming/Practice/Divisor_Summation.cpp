#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back

#define II ({ ll TEMP; cin>>TEMP; TEMP; })

#define CLR(a) memset(a, 0, sizeof(a))
#define endl '\n'

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
const int N = 1e5 + 9;
#define all(v) v.begin(), v.end()

int d[N];

int main()
{
    FAST;

#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    // freopen("F:\GIT\input.txt", "r", stdin);

    // Printing the Output to output.txt file
    // freopen("F:\GIT\output.txt", "w", stdout);
    //
#endif

    ll t = 1;
    cin >> t;

    for(int i=0;i<N;i++)d[i]=0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            d[j] += i;
        }
    }

    while (t--)
    {

        int n;
        cin >> n;

        cout << d[n]-n+1 << endl;
      
    }
    return 0;
}

// cerr << "\n\n\n"
//      << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
