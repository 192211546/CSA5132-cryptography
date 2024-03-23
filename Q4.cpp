#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char *plaintext, char *key) {
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            char offset = isupper(plaintext[i]) ? 'A' : 'a';
            int keyIndex = tolower(key[j % keyLen]) - 'a';
            int shift = tolower(plaintext[i]) - offset;
            plaintext[i] = offset + (shift + keyIndex) % 26;
            ++j;
        }
    }
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    vigenereCipher(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

