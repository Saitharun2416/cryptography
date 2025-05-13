#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipher(char cipher[]) {
    char keyword[] = "CIPHER";
    int used[26] = {0};
    int index = 0;

    // Add keyword letters first
    for (int i = 0; i < strlen(keyword); i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining unused letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
        }
    }
}

void encrypt(char plain[], char cipher[]) {
    printf("Ciphertext: ");
    for (int i = 0; plain[i] != '\0'; i++) {
        char ch = plain[i];
        if (isalpha(ch)) {
            char enc = isupper(ch) ? cipher[ch - 'A'] : tolower(cipher[ch - 'a']);
            printf("%c", enc);
        } else {
            printf("%c", ch); // Keep non-alphabet characters as is
        }
    }
    printf("\n");
}

int main() {
    char cipher[26];
    char plaintext[100];

    generateCipher(cipher);

    printf("Enter plaintext (lowercase or uppercase letters): ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, cipher);

    return 0;
}

