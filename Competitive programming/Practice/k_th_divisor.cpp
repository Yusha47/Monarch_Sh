#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n,k; cin >> n >> k;
  vector<long long > divs;
  for (int i = 1;(long long) i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) divs.push_back(n / i);
    }
  }
  sort(divs.begin(), divs.end());

  
  if(divs.size()<k)
  {
    cout<<-1<<endl;
    return 0;
  }
  cout<<divs[k-1]<<endl;
  return 0;
}