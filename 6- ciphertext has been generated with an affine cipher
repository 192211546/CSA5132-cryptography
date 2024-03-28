#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

char decrypt(char cipherChar, int a, int b) {
    if (isalpha(cipherChar)) {
        char base = isupper(cipherChar) ? 'A' : 'a';
        int inv_a = modInverse(a, 26);
        return (inv_a * (cipherChar - base - b + 26)) % 26 + base;
    }
    return cipherChar;
}

int main() {
    char ciphertext[] = "BBUUAA";
    int freqB = 2; // Frequency of "B"
    int freqU = 1; // Frequency of "U"
    int a, b;

    for (a = 1; a < 26; a++) {
        if ((freqB * modInverse(a, 26)) % 26 == (freqU - freqB + 26) % 26) {
            b = (freqB - a * ('B' - 'A')) % 26;
            if (b < 0) b += 26;
            break;
        }
    }

    printf("Possible decryption: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        printf("%c", decrypt(ciphertext[i], a, b));
    }
    printf("\n");

    return 0;
}

