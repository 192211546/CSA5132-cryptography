#include <stdio.h>
#include <string.h>

#define ROWS 10
#define COLS 6

void decryptPlayfair(const char *encodedMessage, char (*matrix)[COLS], char *decodedMessage) {
    int i, j, k = 0;
    for (i = 0; i < strlen(encodedMessage); i += 2) {
        char a = encodedMessage[i];
        char b = encodedMessage[i + 1];
        int x1, y1, x2, y2;
        for (j = 0; j < ROWS; j++) {
            for (k = 0; k < COLS; k++) {
                if (matrix[j][k] == a) {
                    x1 = j;
                    y1 = k;
                }
                if (matrix[j][k] == b) {
                    x2 = j;
                    y2 = k;
                }
            }
        }
        if (x1 == x2) {
            decodedMessage[i] = matrix[x1][(y1 + 4) % 5];
            decodedMessage[i + 1] = matrix[x2][(y2 + 4) % 5];
        } else if (y1 == y2) {
            decodedMessage[i] = matrix[(x1 + 4) % 5][y1];
            decodedMessage[i + 1] = matrix[(x2 + 4) % 5][y2];
        } else {
            decodedMessage[i] = matrix[x1][y2];
            decodedMessage[i + 1] = matrix[x2][y1];
        }
    }
    decodedMessage[i] = '\0'; 
}

int main() {
    char matrix[ROWS][COLS] = {
        {'K', 'X', 'J', 'E', 'Y', ' '},
        {'U', 'R', 'E', 'B', 'E', ' '},
        {'Z', 'W', 'E', 'H', 'E', ' '},
        {'W', 'R', 'Y', 'T', 'U', ' '},
        {'H', 'E', 'Y', 'F', 'S', ' '},
        {'K', 'R', 'E', 'H', 'E', ' '},
        {'G', 'O', 'Y', 'F', 'I', ' '},
        {'W', 'T', 'T', 'T', 'U', ' '},
        {'O', 'L', 'K', 'S', 'Y', ' '},
        {'C', 'A', 'J', 'P', 'O', ' '}
    };
    char encodedMessage[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char decodedMessage[1000];

    decryptPlayfair(encodedMessage, matrix, decodedMessage);

    printf("Decrypted message: %s\n", decodedMessage);

    return 0;
}

