#include <iostream>
using namespace std;

string canAchieveMinimumCoins(int k, int x, int a) {
    long long maxLoss = (long long)x * (k - 1);
    if ((long long)a - maxLoss * (k - 1) >= 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int k, x, a;
        cin >> k >> x >> a;
        cout << canAchieveMinimumCoins(k, x, a) << endl;
    }

    return 0;
}
