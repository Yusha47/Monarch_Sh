#include<bits/stdc++.h>
using namespace std;
using ll= long long;
long long numberOfDivisors(long long num) {
    long long total = 1;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}
ll GCD(ll a ,ll b)
{
    if(a==0) return b;
    if(b==0) return a;
    if(a<b) swap (a,b);

    return GCD(a%b,b);
}
int32_t main()
{
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
    int t=1;
    //cin>>t;


    while(t--)
    {
        int n;
        cin>>n;
        ll res=0;
        for(int i=0;i<n;i++)
        {
            ll temp; cin>>temp;
             res=GCD(res,temp);
        }


        cout<<numberOfDivisors(res);

    }
    return 0;

}







