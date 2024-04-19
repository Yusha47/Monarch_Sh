#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int f(const string& s) {
    int n = s.size();
    vector<int> pref(n + 1, 0); // Prefix sums of 1s
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (s[i] - '0');
    }

    int ans = 0;
    // Sliding window for different substring lengths
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) { // Iterate over substrings of length l
            int num_ones = pref[i + l] - pref[i];
            int max_freq = 0;

            // Count frequencies using sliding window
            int j = i;
            int freq[2] = {0, 0}; // Frequency of 0s and 1s
            while (j < i + l) {
                int digit = s[j] - '0';
                ++freq[digit];
                max_freq = max(max_freq, freq[digit]);
                ++j;
            }

            // Check if substring is 1-good:
            // Consider all characters, not just distinct ones
            if (max_freq <= l / 2) {
                ans += num_ones;
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int result = f(s);
        cout << result << endl;
    }

    return 0;
}
