#include<bits/stdc++.h>
using namespace std;

// Function to generate a random cipher key
std::map<char, char> generateCipherKey() {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string shuffledAlphabet = alphabet;
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(shuffledAlphabet.begin(), shuffledAlphabet.end(), g);

    std::map<char, char> cipherKey;
    for (size_t i = 0; i < alphabet.length(); ++i) {
        cipherKey[alphabet[i]] = shuffledAlphabet[i];
    }
    return cipherKey;
}

// Function to encrypt a message using the cipher key
std::string encrypt(const std::string& message, const std::map<char, char>& cipherKey) {
    std::string encryptedMessage;
    for (char c : message) {
        if (isalpha(c)) {
            char encryptedChar = cipherKey.at(tolower(c));
            if (isupper(c)) {
                encryptedChar = toupper(encryptedChar);
            }
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to decrypt an encrypted message using the cipher key
std::string decrypt(const std::string& encryptedMessage, const std::map<char, char>& cipherKey) {
    std::map<char, char> decryptionKey;
    for (const auto& pair : cipherKey) {
        decryptionKey[pair.second] = pair.first;
    }

    std::string decryptedMessage;
    for (char c : encryptedMessage) {
        if (isalpha(c)) {
            char decryptedChar = decryptionKey.at(tolower(c));
            if (isupper(c)) {
                decryptedChar = toupper(decryptedChar);
            }
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}
int main()
{
    //FAST;

   #ifndef ONLINE_JUDGE

    // For getting input from input.txt file
  freopen("input.txt", "r", stdin);
//
//    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
//
    #endif


    string message;
    getline(cin,message);
 
    std::map<char, char> cipherKey = generateCipherKey();

    std::string encrypted = encrypt(message, cipherKey);
    std::cout << "Encrypted: " << encrypted << std::endl;

    std::string decrypted = decrypt(encrypted, cipherKey);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;

}




// cerr << "\n\n\n"
//      << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;






