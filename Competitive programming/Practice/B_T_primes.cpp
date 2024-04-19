#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
const long long M = 1e12 + 9;
bool f[N];

using ll= long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = N - 9;
  vector<int> primes;
  f[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!f[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        f[j] = true;
      }
    }
  }



    
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    long long temp;
    cin>>temp;
    int p = sqrtl(temp);
   ;
    if(1LL*p*p==1LL*temp)
    {
        if(!f[p] || p==2)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
  }
  return 0;
}