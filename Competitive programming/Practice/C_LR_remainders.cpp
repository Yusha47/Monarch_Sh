#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;

        unsigned long long product = 1;
            for (int i = 0; i < a.size(); ++i)
            {
                product = (product*a[i]);
            }
        for (int i = 0; i < n; i++)
        {
           
            cout<<product%m<<" ";
            if (s[i] == 'L')
            {
                long long minus = a[0];

                product =(product/minus);
                
                a.erase(a.begin());
            }
            else
            {
                long long lastElement = a[a.size() - 1];
                product =(product/lastElement);
                a.pop_back();
            }
        }

        cout << endl;
    }
    return 0;
}