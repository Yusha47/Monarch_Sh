/*
  Author: MEHEDI ISLAM REMON
  AUST CSE 44th Batch
*/
#include<bits/stdc++.h>
#define ll      long long int
#define nline   "\n"
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(nullptr); cout.tie(nullptr);
#define pb      push_back
#define pi      acos(-1)
#define Mod     1000000007
#define sn      10000000011
#define MAX     intONG_MAX
#define F       first
#define S       second
using namespace std;
 
int main()
{
    fast;
 
 
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>>v(n,vector<ll>(n));
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                cin>>v[i][j];
            }
        }
        if(n==1)
        {
            cout<<"YES"<<endl;
            cout<<7<<endl;
            continue;
        }
 
        vector<ll>res(n,1073741823);
 
 
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                res[i]=res[i]&v[i][j];
            }
        }
 
 
        ll flag=1;
        for(ll i=0; i<n; i++)
        {
            for(ll j=i+1; j<n; j++)
            {
                if((res[i]|res[j])!=v[i][j])
                {
                    flag=0;
                    break;
                }
 
            }
            if(!flag)
                break;
 
        }
        /*for(ll i=0; i<n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;*/
 
 
        if(flag)
        {
            cout<<"YES"<<endl;
            for(ll i=0; i<n; i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
 
 
    }
 
}