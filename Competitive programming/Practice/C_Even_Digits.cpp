#include <iostream>
#include <cmath>
using namespace std;

long long calculate_b_j(long long n, long long j, long long m) {
    return (n - 1 - pow(5, m)) / pow(5, j);
}

long long generateNthGoodInteger(long long n) {
    if (n <= 1) {
        return n * 2;
    }

    long long m = floor(log(n - 1) / log(5));
    long long result = 0;

    // Calculate the first part of the number
    result += ((2 * calculate_b_j(n, m, m)) % 8 + 2) * pow(10, m);

    // Calculate the second part of the number
    for (long long j = 0; j < m; ++j) {
        long long b_j = calculate_b_j(n, j, m);
        result += ((2 * b_j) % 10) * pow(10, j);
    }

    return result;
}

int main() {
    for (long long i = 1; i <= 1e6; ++i) {
        long long result = generateNthGoodInteger(i);
        cout << i << ": " << result << endl;
    }

    return 0;
}
