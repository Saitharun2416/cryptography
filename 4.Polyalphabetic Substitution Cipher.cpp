#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char plaintext[], char key[]) {
    int i, j;
    char cipher[1000];
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < textLen; i++) {
        char p = toupper(plaintext[i]);

        if (isalpha(p)) {
            char k = toupper(key[j % keyLen]);
            int shift = k - 'A';
            cipher[i] = ((p - 'A' + shift) % 26) + 'A';
            j++;  // Move key index only for letters
        } else {
            cipher[i] = plaintext[i];  // Keep non-alphabet characters
        }
    }
    cipher[i] = '\0';

    printf("Encrypted message: %s\n", cipher);
}

int main() {
    char plaintext[1000], key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(plaintext, key);

    return 0;
}

