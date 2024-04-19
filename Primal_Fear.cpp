#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int spf[N];
bool is_valid[N];
int suf[N];
bool valid(int n)
{
    if (spf[n] != n)
    {
        return false;
    }

    int temp = n;
    while (temp)
    {
        if (temp % 10 == 0)
        {
            return false;
        }
        temp /= 10;
    }
    string s = to_string(n);

    int len = s.length();

    for (int j = 0; j < len; j++)
    {
        string sub = s.substr(j);

        int in_num = stoi(sub);
        if (spf[in_num] != in_num)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;

    for (int i = 2; i < N; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            spf[j] = min(spf[j], i);
        }
    }

    for (int i = 1; i < N; i++)
    {
        is_valid[i] = valid(i);
    }

    for (int i = 1; i < N; i++)
    {
        suf[i] += suf[i - 1] + is_valid[i];
    }

    while (t--)
    {

        int n;
        cin >> n;
        cout << suf[n] << "\n";
    }
    return 0;
}
