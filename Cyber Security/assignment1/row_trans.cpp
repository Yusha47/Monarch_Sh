#include<bits/stdc++.h>
using namespace std;
std::string encrypt(const std::string& plaintext, const std::string& key) {
    int cols = key.length();
    int rows = (plaintext.length() + cols - 1) / cols;
    char matrix[rows][cols];

    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (index < plaintext.length())
                matrix[i][j] = plaintext[index++];
            else
                matrix[i][j] = 'x'; // Padding if needed
        }
    }

    std::string encrypted;
    for (char c : key) {
        int col = c - '0' - 1;
        for (int i = 0; i < rows; ++i) {
            if (isalpha(matrix[i][col]) || matrix[i][col] == ' ')
                encrypted += matrix[i][col];
        }
    }

    return encrypted;
}

std::string decrypt(const std::string& ciphertext, const std::string& key) {
    int cols = key.length();
    int rows = (ciphertext.length() + cols - 1) / cols;
    char matrix[rows][cols];

    int index = 0;
    for (char c : key) {
        int col = c - '0' - 1;
        for (int i = 0; i < rows; ++i) {
            matrix[i][col] = ciphertext[index++];
        }
    }

    std::string decrypted;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (isalpha(matrix[i][j]) || matrix[i][j] == ' ')
                decrypted += matrix[i][j];
        }
    }

    return decrypted;
}

int main() {
    std::string key = "43251";
   
    std::string plaintext = "meet me as soon as you come back";

    // Encrypt the plaintext
    std::string encrypted = encrypt(plaintext, key);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    // Decrypt the ciphertext
    std::string decrypted = decrypt(encrypted, key);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
