#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

void generateCipherAlphabet(const char *keyword, char *cipherAlphabet) {
    int keywordLength = strlen(keyword);
    int i, j;
    strcpy(cipherAlphabet, keyword);
    int used[ALPHABET_SIZE] = {0};
    for (i = 0; i < keywordLength; i++) {
        if (isalpha(keyword[i])) {
            used[toupper(keyword[i]) - 'A'] = 1;
        }
    }

   for (i = 0, j = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipherAlphabet[keywordLength + j++] = 'A' + i;
        }
    }
    cipherAlphabet[keywordLength + j] = '\0';
}

void encrypt(const char *plaintext, const char *keyword, char *ciphertext) {
    char cipherAlphabet[ALPHABET_SIZE + 1];
    generateCipherAlphabet(keyword, cipherAlphabet);

    int i;
    int length = strlen(plaintext);

    for (i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char plainChar = toupper(plaintext[i]);
            if (plainChar >= 'A' && plainChar <= 'Z') {
                ciphertext[i] = cipherAlphabet[plainChar - 'A'];
            } else {
    
                ciphertext[i] = plaintext[i];
            }
        } else {
        
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[1000];
    char keyword[] = "CIPHER";
    char ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, keyword, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}

