#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

using namespace std;

string encryptAES(const string& plainText, const string& key) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &encryptKey);
    unsigned char encrypted[16];
    AES_encrypt(reinterpret_cast<const unsigned char*>(plainText.c_str()), encrypted, &encryptKey);
    return string(reinterpret_cast<char*>(encrypted), 16);
}

