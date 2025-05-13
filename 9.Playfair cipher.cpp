#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to prepare the Playfair matrix
void prepareMatrix(char *keyword, char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int index = 0;
    
    // Fill the matrix with the keyword
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (ch == 'J') ch = 'I'; // 'J' treated as 'I'
        if (!used[ch - 'A']) {
            matrix[index / SIZE][index % SIZE] = ch;
            used[ch - 'A'] = 1;
            index++;
        }
    }

    // Fill the rest with unused letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch - 'A']) {
            matrix[index / SIZE][index % SIZE] = ch;
            index++;
        }
    }
}

// Function to decrypt a pair of letters
void decryptPair(char a, char b, char matrix[SIZE][SIZE], char *result) {
    int row1, col1, row2, col2;
    
    // Find positions of letters in the matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == a) { row1 = i; col1 = j; }
            if (matrix[i][j] == b) { row2 = i; col2 = j; }
        }
    }

    if (row1 == row2) { // Same row: shift left
        result[0] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
        result[1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
    } else if (col1 == col2) { // Same column: shift up
        result[0] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
        result[1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
    } else { // Rectangle: swap columns
        result[0] = matrix[row1][col2];
        result[1] = matrix[row2][col1];
    }
}

// Function to decrypt the entire message
void decryptMessage(char *ciphertext, char matrix[SIZE][SIZE]) {
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        char first = toupper(ciphertext[i]);
        char second = toupper(ciphertext[i + 1]);
        char result[2];
        
        decryptPair(first, second, matrix, result);
        printf("%c%c", result[0], result[1]);
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "KXJEY ÜREBE ZWEHE WRYTU HEYFS";
    char matrix[SIZE][SIZE];
    
    // Prepare the matrix using the keyword "CIPHER"
    prepareMatrix("CIPHER", matrix);
    
    // Decrypt the message
    decryptMessage(ciphertext, matrix);
    
    return 0;
}

