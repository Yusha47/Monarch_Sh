#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string x, y;
        cin >> x >> y;

        int n = x.size();

        // Find the maximum digit in x and y
        char maxX = '0', maxY = '0';
        for (int i = 0; i < n; ++i) {
            if (x[i] > maxX) maxX = x[i];
            if (y[i] > maxY) maxY = y[i];
        }

        // If both numbers have the same highest digit, swap any other pair of digits
        if (maxX == maxY) {
            swap(x[0], y[1]); // Swapping the highest digit of x with the second highest digit of y
        } else {
            // Otherwise, swap the highest digit of x with the highest digit of y
            for (int i = 0; i < n; ++i) {
                if (x[i] == maxX) {
                    swap(x[i], y[0]);
                    break;
                }
            }
        }

        cout << x << endl;
        cout << y << endl;
    }

    return 0;
}
