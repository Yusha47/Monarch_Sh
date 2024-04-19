#include<bits/stdc++.h>
using namespace std;
using ll= long long;

int32_t main()
{
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
    

    ll n,m,l,r;cin>>n>>m>>l>>r;


    int GCD=__gcd(n,m);

    if(n/GCD>r/m)
    {
        cout<<0<<endl;
        return 0;
    }
    ll lcm=(n/GCD)*m;

    cout<<r/lcm-(l-1)/lcm<<endl;;





    return 0;

}







