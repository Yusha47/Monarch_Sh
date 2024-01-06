#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<int> getDigitsFromSubsetSums(const vector<int> &nums) {
    unordered_set<int> uniqueDigits;

    int n = nums.size();

    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += nums[i];
            }
        }

        while (sum > 0) {
            uniqueDigits.insert(sum % 10); // Insert each digit into the set
            sum /= 10;
        }
    }

    return uniqueDigits;
}

void solve() {
    int n;
    cin >> n;

    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; ++i) {
        char c;
        int temp;
        cin >> c >> temp;

        if (c == '1') {
            x.push_back(pow(2, temp));
        } else {
            y.push_back(temp);
        }
    }

    unordered_set<int> digitsSet = getDigitsFromSubsetSums(x);

    for (auto digit : y) {
        if (digitsSet.find(digit) != digitsSet.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
