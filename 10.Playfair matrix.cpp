#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to find position of a character in the matrix
void findPosition(char ch, char matrix[SIZE][SIZE], int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of letters
void encryptPair(char a, char b, char matrix[SIZE][SIZE], char *result) {
    int row1, col1, row2, col2;
    findPosition(a, matrix, &row1, &col1);
    findPosition(b, matrix, &row2, &col2);
    if (row1 == row2) {
        result[0] = matrix[row1][(col1 + 1) % SIZE];
        result[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        result[0] = matrix[(row1 + 1) % SIZE][col1];
        result[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}

// Main function
int main() {
    char matrix[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'J'},
        {'K', 'U', 'N', 'O', 'P'},
        {'Q', 'Z', 'V', 'W', 'X'},
        {'Y', 'E', 'L', 'A', 'R'},
        {'G', 'D', 'S', 'T', 'B'}
    };

    char message[] = "Must see you over Cadogan West.";
    char preparedMessage[100];
    
    // Remove spaces and convert to uppercase
    int j = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            preparedMessage[j++] = toupper(message[i]);
        }
    }
    preparedMessage[j] = '\0';

    // Process message in pairs
    for (int i = 0; i < strlen(preparedMessage); i += 2) {
        char result[2];
        encryptPair(preparedMessage[i], preparedMessage[i + 1], matrix, result);
        printf("%c%c", result[0], result[1]);
    }

    printf("\n");
    return 0;
}

