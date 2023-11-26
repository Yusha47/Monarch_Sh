#include <iostream>
#include <string>
using namespace std;

string cleanKey(string key) {
    string cleanedKey;
    for (char &c : key) {
        if (isalpha(c)) {
            if (islower(c))
                cleanedKey += toupper(c);
            else
                cleanedKey += c;
        }
    }
    return cleanedKey;
}

string encrypt(string text, string key) {
    string out;
    key = cleanKey(key);
    int keyLength = key.length();
    int textLength = text.length();

    for (int i = 0, j = 0; i < textLength; ++i) {
        char c = text[i];

        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            out += ((c - offset + key[j] - 'A') % 26) + offset;
            j = (j + 1) % keyLength;
        } else {
            out += c;
        }
    }
    return out;
}

string decrypt(string text, string key) {
    string out;
    key = cleanKey(key);
    int keyLength = key.length();
    int textLength = text.length();

    for (int i = 0, j = 0; i < textLength; ++i) {
        char c = text[i];

        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            out += ((c - offset - (key[j] - 'A') + 26) % 26) + offset;
            j = (j + 1) % keyLength;
        } else {
            out += c;
        }
    }
    return out;
}

int main() {

    
   #ifndef ONLINE_JUDGE

    // For getting input from input.txt file
  freopen("input.txt", "r", stdin);
//
//    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
//
    #endif

    string key, message;

   // cout << "Enter the key: ";
    getline(cin, key);

    //cout << "Enter the message: ";
    getline(cin, message);

    string encrypted = encrypt(message, key);
    string decrypted = decrypt(encrypted, key);

   cout << "Original Message: " << message << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
