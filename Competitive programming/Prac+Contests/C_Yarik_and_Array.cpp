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

ll t=0;
void solve()
{
   // t++;
    //cout<<t<<endl;
    ll n=II;
    vector<ll>arr(n);
    vector<ll>x;
    ll max1=-1e5;

    ll idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max1<arr[i])
        {
            max1=arr[i];
            idx=i;

        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==max1)
        {
            x.pb(i);
        }
    }
    //VO(x);
    vector<ll>ans;
    vector<ll>ans2;
    for(auto a : x)
    {
       ll flag=0;
        ll sum=0;
        for(int i=a-1;i>=0;i--)
        { 
            
            if(abs(arr[i])%2!=abs(arr[i+1])%2)
            {
                sum+=arr[i];
                
                ans.pb(sum);
                flag=1;
            }
            else break;

        }
        if(flag==0)
        {

             ans.pb(sum);
        }
       
        ll sum2=0;
         for(int i=a+1;i<n;i++)
        {
           
           
            
            if(abs(arr[i]%2)!=abs(arr[i-1])%2)
            {
               // dbg(i);
               // dbg(arr[i]);
                sum2+=arr[i];
               
                ans2.pb(sum2);
            }
            else break;

        }
        
        

       
    }
    ll result=0;
    sort(all(ans),greater<ll>());
    sort(all(ans2),greater<ll>());
    //VO(ans);
  // VO(ans2);
    if(ans.size()!=0)
    {
        if(ans[0]>0)
        result+=ans[0];
        
    }
   
     if(ans2.size()!=0)
    {
        if(ans2[0]>0)
        result+=ans2[0];
    }
    cout<<result+max1<<endl;



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






