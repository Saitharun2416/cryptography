#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[]) {
    int used[26] = {0};
    used['J' - 'A'] = 1; // Treat I and J as the same
    int k = 0;
    char ch;

    for (int i = 0; key[i] != '\0'; i++) {
        ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

void encrypt(char text[]) {
    int i, row1, col1, row2, col2;
    printf("Encrypted message: ");
    for (i = 0; i < strlen(text); i += 2) {
        char a = toupper(text[i]);
        char b = toupper(text[i + 1]);

        if (a == b) b = 'X';  // avoid repeating same letter in pair

        findPosition(a, &row1, &col1);
        findPosition(b, &row2, &col2);

        if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 + 1) % 5], matrix[row2][(col2 + 1) % 5]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 + 1) % 5][col1], matrix[(row2 + 1) % 5][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char key[100] = "MONARCHY";
    char text[100] = "HELLO";

    createMatrix(key);

    // Add 'X' if odd length
    if (strlen(text) % 2 != 0) strcat(text, "X");

    printf("Keyword: %s\n", key);
    printf("Plaintext: %s\n", text);

    encrypt(text);

    return 0;
}

