#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherSequence(char *keyword, char *cipherSequence) {
    int len = strlen(keyword);
    int index = 0;

    strcpy(cipherSequence, keyword);

    for (int i = 0; i < len; i++) {
        if (isalpha(keyword[i])) {
            cipherSequence[toupper(keyword[i]) - 'A'] = '*';
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (cipherSequence[ch - 'A'] != '*') {
            cipherSequence[ch - 'A'] = ch;
        }
    }
}

void encrypt(char *plaintext, char *cipherSequence, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = cipherSequence[toupper(plaintext[i]) - base];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "hello world";
    char cipherSequence[26];
    char ciphertext[strlen(plaintext) + 1];

    generateCipherSequence(keyword, cipherSequence);
    encrypt(plaintext, cipherSequence, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

