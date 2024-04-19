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
    ll n=II,x=II,y=II;
    vector<ll>v(n);

    map<ll,ll>mpx;
    map<ll,ll>mpy;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        if(x>v[i])
        {
            mpx[x-v[i]]++; 
        }
        else if(x<v[i])
        {
            mpx[v[i]%x]++;
        }
            if(y>v[i])
        {
            mpy[y-v[i]]++; 
        }
        else if(y<v[i])
        {
            mpy[v[i]%y]++;
        }
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(x>v[i])
        {
            ll temp=x-v[i];
            outa(v[i]);
            outa(temp);

            if(mpx[temp]>=2)
            {
                if(y>v[i])
                {
                    ll tempy=y-v[i];
                    outa(tempy);
                    if(mpy[tempy]>=2)
                    {
                        ans+=min(mpx[temp]/2,mpy[tempy]/2);
                    }
                }
                else if(y<v[i])
                {
                    ll tempy=v[i]%y;
                    if(mpy[tempy]>=2)
                    {
                        ans+=min(mpx[temp]/2,mpy[tempy]/2);
                    }
                }
                
            }
        outa(ans);
        }
      else if(x<v[i])
        {
            ll temp=v[i]%x;
            cout<<v[i]<<" "<<temp<<endl;
            if(mpx[temp]>=2)
            {
                if(y>v[i])
                {
                    ll tempy=y%v[i];
                    if(mpy[tempy]>=2)
                    {
                        ans+=min(mpx[temp],mpy[tempy]);
                    }
                }
                else if(y<v[i])
                {
                    ll tempy=v[i]%y;
                    if(mpy[tempy]>=2)
                    {
                        ans+=min(mpx[temp],mpy[tempy]);
                    }
                }
                
            }
        
        }
    }

    outa(ans);
    for(auto p: mpx)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"SHESH"<<endl;
    for(auto p: mpy)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"SHESH2"<<endl;

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






