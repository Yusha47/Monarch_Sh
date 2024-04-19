#include<bits/stdc++.h>
using namespace std;
using ll= long long;

int32_t main()
{
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
    

    int n;
    cin>>n;
    vector<int>x;
     int temp=n/2;
    
        for(int i=0;i<temp-1;i++)
        {
           x.push_back(2);
        }
    if(n%2!=0)
    {
        x.push_back(3);
    }
    else
    {
        x.push_back(2);
    }
    cout<<x.size()<<endl;
    for(auto c :x)
    {
        cout<<c<<" ";
    }

    return 0;

}







