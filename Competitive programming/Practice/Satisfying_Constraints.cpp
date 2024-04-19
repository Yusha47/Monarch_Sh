#include<bits/stdc++.h>
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
#define VI(v) ({ rep(I,0,v.size())v[I]=II; })
#define VO(v) ({ rep(I,0,v.size()){cout<<(I?" ":"")<<v[I];} if(DEBUGGER)cout<<endl;else cout<<'\n'; })
#define dbg(a) ({ if(DEBUGGER)cout<<#a<<" = "<<a<<endl; })
#define outa(a) ({ if(DEBUGGER)dbg(a); else cout<<a<<'\n'; })

#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,a,n) for(int i=n-1;i>=a;i--)
#define repSe(i,st,end) for(int i=st;i<end;i++)
#define repS0(i,st,end) for(int i=st;i>0;i--)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define endl '\n'
#define MOD 1000000007
#define MX 105
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
const int INF = 1e9 + 7;
#define all(v) v.begin(), v.end()


vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},{-1,-1},{-1,1},{1,1},{1,-1}};

bool check(ll x,ll y,ll h,ll w)
{
    if(x<1 || x>h || y<1 || y>w)
    {
        return false;
    }
    else return true;
}

ll sum(ll n1) {
    return (n1*(n1+1))/2;
    
}


void solve()
{
    ll n=II;

    ll max_1=LLONG_MAX;
    ll min_1=LLONG_MIN;
    vector<ll>x;
    while(n--)
    {
        ll temp1,temp2;
        cin>>temp1;
        cin>>temp2;

        if(temp1==1ll)
        {
            min_1=max(min_1,temp2);
        }
        else if(temp1==2ll)
        {
            max_1=min(max_1,temp2);
        }
       else if(temp1==3ll)
        {
            x.pb(temp2);
        }
    }
    //VO(x);
    //outa(min_1);
    //outa(max_1);
    if(min_1>max_1)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=(max_1-min_1)+1;
    for(auto i:x)
    {
        if(i>=min_1 && i<=max_1)
        {
            ans--;
            
        }
    }
    cout<<ans<<endl;

}
int main()
{
    //FAST;

   #ifndef ONLINE_JUDGE

   // For getting input from input.txt file
   //freopen("F:\GIT\input.txt", "r", stdin);

    // Printing the Output to output.txt file
  // freopen("F:\GIT\output.txt", "w", stdout);
//
    #endif

    ll t=1;
    cin>>t;


    while(t--)
    {



        solve();


    }
    return 0;

}




// cerr << "\n\n\n"
//      << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;






