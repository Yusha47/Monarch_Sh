#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the lps array using the KMP algorithm
vector<int> computeLPS(const string& s) {
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0; // Length of the previous longest prefix suffix

    int i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to find the length of the shortest string k
int shortestK(const string& s) {
    int n = s.length();
    vector<int> lps = computeLPS(s);
    int len = n - lps[n - 1];
    if (n % len == 0 && len != n) {
        // Check if substring of length 'len' can form the whole string
        string substring = s.substr(0, len);
        bool isRepeating = true;
        for (int i = len; i < n; i += len) {
            if (s.substr(i, len) != substring) {
                isRepeating = false;
                break;
            }
        }
        if (isRepeating)
            return len;
    }
    return n;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << shortestK(s) << endl;
    }

    return 0;
}
