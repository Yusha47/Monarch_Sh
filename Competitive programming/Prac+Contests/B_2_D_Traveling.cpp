#include<bits/stdc++.h>
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
using namespace std;

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
ll distance(vector<pair<ll,ll>>&x,ll a,ll b,ll k) 
{ 
    // Calculating distance

    if(a<=k && b<=k)
    {
        return 0;
    } 
   
    return abs(x[a].first-x[b].first)+abs(x[a].second-x[b].second);
}

void solve()
{
    ll n=II,k=II,a=II,b=II;

    vector<pair<ll,ll>>x(n+1);

    rep(i,1,n+1)
    {
        ll temp1=II,temp2=II;
        x[i].first=temp1;
        x[i].second=temp2;    
    }
    // rep(i,0,n)
    // {
        
    //     dbg(x[i].first);
    //     dbg(x[i].second);    
    // }

    ll starting_distance=distance(x,a,b,k);
   // dbg(starting_distance);
    ll bans=1e10;
    ll aans=1e10;
   
    rep(i,1,k+1)
    {
      
            bans=min(bans,(distance(x,i,b,k)));
            aans=min(aans,distance(x,i,a,k));
       


    }
   
    cout<<min(starting_distance,bans+aans)<<endl;


}
int main()
{
    //FAST;

   #ifndef ONLINE_JUDGE

    // For getting input from input.txt file
  // freopen("input.txt", "r", stdin);
//
//    // Printing the Output to output.txt file
   // freopen("output.txt", "w", stdout);
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






