#include <stdio.h>
#include <ctype.h>

int main() {
    char msg[1000];
    int k;

    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &k);

    for (int i = 0; msg[i] != '\0'; i++) {
        char ch = msg[i];
        if (isupper(ch))
            msg[i] = ((ch - 'A' + k) % 26) + 'A';
        else if (islower(ch))
            msg[i] = ((ch - 'a' + k) % 26) + 'a';
    }

    printf("Encrypted message: %s", msg);
    return 0;
}

