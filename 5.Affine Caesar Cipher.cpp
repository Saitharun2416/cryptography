#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find modular inverse of a mod 26
int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1; // No inverse exists
}

// Function to encrypt
void encrypt(char msg[], int a, int b) {
    printf("Encrypted text: ");
    for (int i = 0; msg[i] != '\0'; i++) {
        if (isalpha(msg[i])) {
            char ch = toupper(msg[i]);
            int p = ch - 'A';
            int c = (a * p + b) % 26;
            printf("%c", c + 'A');
        } else {
            printf("%c", msg[i]);
        }
    }
    printf("\n");
}

// Function to decrypt
void decrypt(char msg[], int a, int b) {
    int a_inv = modInverse(a);
    if (a_inv == -1) {
        printf("Decryption not possible (a and 26 are not coprime).\n");
        return;
    }

    printf("Decrypted text: ");
    for (int i = 0; msg[i] != '\0'; i++) {
        if (isalpha(msg[i])) {
            char ch = toupper(msg[i]);
            int c = ch - 'A';
            int p = (a_inv * (c - b + 26)) % 26;
            printf("%c", p + 'A');
        } else {
            printf("%c", msg[i]);
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    int a = 5, b = 8;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, a, b);
    decrypt(message, a, b);

    return 0;
}

