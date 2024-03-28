#include <stdio.h>
#include <ctype.h>

int areRelativelyPrime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

char encrypt(char plainChar, int a, int b) {
    if (isalpha(plainChar)) {
        char base = isupper(plainChar) ? 'A' : 'a';
        return (a * (plainChar - base) + b) % 26 + base;
    }
    return plainChar;
}

int main() {
    char plaintext[100];
    int a, b;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the values of a and b (space-separated): ");
    scanf("%d %d", &a, &b);

    if (!areRelativelyPrime(a, 26)) {
        printf("Error: a and 26 must be relatively prime.\n");
        return 1;
    }

    if (!areRelativelyPrime(b, 26)) {
        printf("Error: b and 26 must be relatively prime.\n");
        return 1;
    }

    printf("Encrypted text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", encrypt(plaintext[i], a, b));
    }
    printf("\n");

    return 0;
}

