#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::map<char, int> order;
    for (int i = 0; i < key.size(); ++i) {
        order[key[i]] = i;
    }

    std::string ciphertext;

    // Determine the number of columns
    int cols = key.size();
    int rows = plaintext.size() / cols + (plaintext.size() % cols ? 1 : 0);

    // Create the matrix
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, ' '));

    // Fill the matrix with the plaintext
    for (int i = 0, k = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (k < plaintext.size()) {
                matrix[i][j] = plaintext[k++];
            } else {
                // Fill with 'x' if plaintext runs out
                matrix[i][j] = 'x';
            }
        }
    }

    // Read the matrix column-wise according to the order
    for (const auto& pair : order) {
        for (int i = 0; i < rows; ++i) {
            char c = matrix[i][pair.second];
            if (c != 'x') {
                ciphertext += c;
            }
        }
    }

    return ciphertext;
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::map<char, int> order;
    for (int i = 0; i < key.size(); ++i) {
        order[key[i]] = i;
    }

    std::string plaintext;

    int cols = key.size();
    int rows = ciphertext.size() / cols + (ciphertext.size() % cols ? 1 : 0);

    // Create the matrix
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, ' '));

    int idx = 0;
    // Fill the matrix column-wise according to the order
    for (const auto& pair : order) {
        int column = pair.second;
        for (int i = 0; i < rows; ++i) {
            matrix[i][column] = ciphertext[idx++];
        }
    }

    // Read the matrix row-wise to obtain the plaintext
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char c = matrix[i][j];
            if (c != 'x') {
                plaintext += c;
            }
        }
    }

    return plaintext;
}

int main() {
    std::string plaintext = "meetmeaftertheparty";
    std::string key = "HACK";

    std::string encrypted = encrypt(plaintext, key);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
