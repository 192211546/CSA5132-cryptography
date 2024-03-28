#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 5

void findPosition(char matrix[ROWS][COLS], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] == ch || (matrix[i][j] == 'J' && ch == 'I')) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptDigraph(char matrix[ROWS][COLS], char ch1, char ch2, char *result) {
    int row1, col1, row2, col2;
    findPosition(matrix, ch1, &row1, &col1);
    findPosition(matrix, ch2, &row2, &col2);

    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + 1) % COLS];
        result[1] = matrix[row2][(col2 + 1) % COLS];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + 1) % ROWS][col1];
        result[1] = matrix[(row2 + 1) % ROWS][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
    result[2] = '\0';
}

void preparePlaintext(char *plaintext) {
    int i, j = 0;
    char preparedText[1000];

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (toupper(plaintext[i]) == 'J')
                preparedText[j++] = 'I'; 
            else
                preparedText[j++] = toupper(plaintext[i]); 
        }
    }

    preparedText[j] = '\0'; 
    strcpy(plaintext, preparedText); 
}

int main() {
    char matrix[ROWS][COLS] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char plaintext[] = "Must see you over Cadogan West. Coming at once.";
    char encryptedText[1000];
    char digraph[3];
    
    preparePlaintext(plaintext);

    int i, j = 0;
    for (i = 0; plaintext[i] != '\0'; i += 2) {
        char ch1 = plaintext[i];
        char ch2 = (plaintext[i + 1] == '\0') ? 'X' : plaintext[i + 1]; 
        encryptDigraph(matrix, ch1, ch2, digraph);
        encryptedText[j++] = digraph[0];
        encryptedText[j++] = digraph[1];
    }
    encryptedText[j] = '\0'; 

    printf("Encrypted message: %s\n", encryptedText);

    return 0;
}

