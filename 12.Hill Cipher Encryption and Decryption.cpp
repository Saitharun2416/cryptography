#include <stdio.h>
#include <string.h>

int key[2][2] = { {9, 4}, {5, 7} }; // Key matrix
int invKey[2][2] = { {7, 22}, {21, 9} }; // Inverse key matrix mod 26

// Function to convert char to int (A=0, B=1, ..., Z=25)
int toInt(char c) {
    return c - 'A';
}

// Function to convert int to char
char toChar(int n) {
    return n + 'A';
}

// Encryption function
void encrypt(char *pt, char *ct) {
    for (int i = 0; i < strlen(pt); i += 2) {
        int x = toInt(pt[i]);
        int y = toInt(pt[i + 1]);
        ct[i] = toChar((key[0][0]*x + key[0][1]*y) % 26);
        ct[i+1] = toChar((key[1][0]*x + key[1][1]*y) % 26);
    }
    ct[strlen(pt)] = '\0';
}

// Decryption function
void decrypt(char *ct, char *pt) {
    for (int i = 0; i < strlen(ct); i += 2) {
        int x = toInt(ct[i]);
        int y = toInt(ct[i + 1]);
        pt[i] = toChar((invKey[0][0]*x + invKey[0][1]*y) % 26);
        pt[i+1] = toChar((invKey[1][0]*x + invKey[1][1]*y) % 26);
    }
    pt[strlen(ct)] = '\0';
}

int main() {
    char pt[] = "MEETMEATTH"; // Message (should be even length and uppercase)
    char ct[100], dec[100];

    encrypt(pt, ct);
    printf("Encrypted: %s\n", ct);

    decrypt(ct, dec);
    printf("Decrypted: %s\n", dec);

    return 0;
}

