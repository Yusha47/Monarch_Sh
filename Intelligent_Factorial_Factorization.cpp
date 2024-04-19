#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int N=100+9;
int spf[N];
int32_t main()
{
    
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
    int t=1;
    cin>>t;
    int cs=1;
   
    for(int i=2;i<N;i++)
    {
        spf[i]=i;
    }
    
    for(int i=2;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            spf[j]=min(spf[j],i);
        }
    }
   

   
   

    while(t--)
    {
        string ans;
        int n;
        cin>>n;
         map<int,int>mp;
        cout<<"Case "<<cs++<<": "<<n<<" = ";
        for(int i=2;i<=n;i++)
        {
            int _n=i;
            while(_n>1)
            {
                mp[spf[_n]]++;
                _n/=spf[_n];
            }

        
        }

        for(auto c : mp)
        {
            ans+=to_string(c.first)+" ("+to_string(c.second)+")"+" * ";
            
        }
        for(int i=0;i<ans.length()-3;i++)
        {
        cout<<ans[i];
        }
        
        cout<<"\n";

    }
    return 0;

}







