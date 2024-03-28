#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKey(char key[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[26] = "abcdefghiklmnopqrstuvwxyz"; // 'j' is omitted
    int len = strlen(key);

    // Copy key to keyMatrix
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (k < len) {
                keyMatrix[i][j] = toupper(key[k]);
                ++k;
            } else {
                // Fill with remaining alphabets
                while (strchr(key, alphabet[k - len]))
                    ++k;
                keyMatrix[i][j] = alphabet[k - len];
                ++k;
            }
        }
    }
}

void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    for (*row = 0; *row < SIZE; ++(*row)) {
        for (*col = 0; *col < SIZE; ++(*col)) {
            if (keyMatrix[*row][*col] == ch)
                return;
        }
    }
}

void encrypt(char keyMatrix[SIZE][SIZE], char ch1, char ch2) {
    int row1, col1, row2, col2;
    findPosition(keyMatrix, toupper(ch1), &row1, &col1);
    findPosition(keyMatrix, toupper(ch2), &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 + 1) % SIZE;
        col2 = (col2 + 1) % SIZE;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % SIZE;
        row2 = (row2 + 1) % SIZE;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c%c%c", keyMatrix[row1][col1], keyMatrix[row2][col2], keyMatrix[row1][col2], keyMatrix[row2][col1]);
}

int main() {
    char key[100], plaintext[100];
    char keyMatrix[SIZE][SIZE];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    printf("Enter the plaintext (in pairs, without spaces): ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline characters from inputs
    key[strcspn(key, "\n")] = '\0';
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Prepare key matrix
    prepareKey(key, keyMatrix);

    // Encrypt plaintext
    printf("Encrypted text: ");
    for (int i = 0; i < strlen(plaintext); i += 2) {
        encrypt(keyMatrix, plaintext[i], plaintext[i + 1]);
    }
    printf("\n");

    return 0;
}

