#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticCipher(char *message, char *key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (isalpha(ch)) {
            if (islower(ch))
                message[i] = tolower(key[ch - 'a']);
            else if (isupper(ch))
                message[i] = toupper(key[ch - 'A']);
        }
    }
}

int main() {
    char message[100];
    char key[26];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (26 unique letters): ");
    fgets(key, sizeof(key), stdin);

    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) != 26) {
        printf("Invalid key! The key must contain exactly 26 unique letters.\n");
        return 1;
    }

    for (int i = 0; i < 26; ++i) {
        if (!isalpha(key[i])) {
            printf("Invalid key! The key must contain only alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; ++j) {
            if (tolower(key[i]) == tolower(key[j])) {
                printf("Invalid key! The key must contain unique letters.\n");
                return 1;
            }
        }
    }

    monoalphabeticCipher(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

