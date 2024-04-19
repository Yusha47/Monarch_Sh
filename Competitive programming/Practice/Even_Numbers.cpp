#include <iostream>
#include <bitset>
#include <cmath>

int reverseBinary(int num) {
    std::bitset<32> binary(num);
    int significantBits = std::log2(num) + 1;
    for (int i = 0; i < significantBits / 2; ++i) {
        bool temp = binary[i];
        binary[i] = binary[significantBits - i - 1];
        binary[significantBits - i - 1] = temp;
    }
    return static_cast<int>(binary.to_ulong());
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int ai;
        std::cin >> ai;

        if (ai % 2 == 0) {
            int modifiedNum = reverseBinary(ai);
            std::cout << modifiedNum << std::endl;
        } else {
            std::cout << ai << std::endl;
        }
    }

    return 0;
}
