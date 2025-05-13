#include <stdio.h>
#include <ctype.h>

int main() {
    char message[1000];
    // Substitution key: A-Z mapped to QWERTYUIOPASDFGHJKLZXCVBNM
    char key[26] = {
        'Q','W','E','R','T','Y','U','I','O','P',
        'A','S','D','F','G','H','J','K','L','Z',
        'X','C','V','B','N','M'
    };

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (isupper(ch)) {
            message[i] = key[ch - 'A'];
        } else if (islower(ch)) {
            message[i] = tolower(key[ch - 'a']);
        }
    }

    printf("Encrypted message: %s", message);
    return 0;
}

