#include <iostream>
#include <cstdlib>

std::pair<int, int> findSmallestAbsoluteDifference(int a, int b, int r) {
    int smallestDifference = INT_MAX;
    int optimalX = -1;

    for (int x = 0; x <= r; ++x) {
        int resultA = a ^ x;
        int resultB = b ^ x;

        int absoluteDifference = abs(resultA - resultB);

        if (absoluteDifference < smallestDifference) {
            smallestDifference = absoluteDifference;
            optimalX = x;
        }
    }

    return std::make_pair(smallestDifference, optimalX);
}

int main() {
    // Example usage
    int a=16, b=14, r=5;
    std::cout << "Enter values for a, b, and r: ";
   

    auto result = findSmallestAbsoluteDifference(a, b, r);

    std::cout << "The smallest absolute difference is: " << result.first << std::endl;
    std::cout << "The corresponding value of x is: " << result.second << std::endl;

    return 0;
}
