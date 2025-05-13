#include <stdio.h>
#include <string.h>

void ecb_encrypt(char plaintext[], char ciphertext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ 0xAA; // Simple XOR with fixed key
    }
    ciphertext[len] = '\0';
}

int main() {
    char plaintext[] = "HELLO";
    char ciphertext[100];
    ecb_encrypt(plaintext, ciphertext);
    
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02X ", ciphertext[i]);
    }
    return 0;
}

