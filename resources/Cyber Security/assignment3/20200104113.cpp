#include<bits/stdc++.h>
using namespace std;

std::string XOR(std::string a, std::string b) {
    std::string result = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

std::string encrypt(std::string plaintext, std::string key, std::string IV) {
    std::string ciphertext = "";
    std::string previous = IV;
    for (int i = 0; i < plaintext.size(); i += key.size()) {
        std::string block = plaintext.substr(i, key.size());
        while (block.size() < key.size())
            block += "0";
        std::string xor_result = XOR(block, previous);
        std::string encrypted_block = XOR(xor_result, key);
        ciphertext += encrypted_block;
        previous = encrypted_block;
    }
    return ciphertext;
}

std::string decrypt(std::string ciphertext, std::string key, std::string IV) {
    std::string plaintext = "";
    std::string previous = IV;
    for (int i = 0; i < ciphertext.size(); i += key.size()) {
        std::string block = ciphertext.substr(i, key.size());
        std::string decrypted_block = XOR(XOR(block, key), previous);
        plaintext += decrypted_block;
        previous = block;
    }
    return plaintext;
}

int main() {
    std::string plaintext = "101010101010101010101010101010101010101010101010"; // Replace with your plaintext
    std::string key = "11111111"; 
    std::string IV = "11110000"; 
    std::string ciphertext = encrypt(plaintext, key, IV);
    std::cout << "Plain Text " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::string decrypted_text = decrypt(ciphertext, key, IV);
    std::cout << "Decrypted text: " << decrypted_text << std::endl;
    return 0;
}
