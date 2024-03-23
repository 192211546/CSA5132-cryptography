#include <stdio.h>
#include <ctype.h>

void caesarCipher(char message[], int key) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (isalpha(ch)) {
            if (islower(ch))
                ch = 'a' + (ch - 'a' + key) % 26;
            else if (isupper(ch))
                ch = 'A' + (ch - 'A' + key) % 26;
        }
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (1 to 25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Invalid key! Key should be in the range 1 to 25.\n");
        return 1;
    }

    caesarCipher(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}

