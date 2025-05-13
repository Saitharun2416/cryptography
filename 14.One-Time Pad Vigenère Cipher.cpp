#include <stdio.h>
int main() {
    char pt[] = "SENDMOREMONEY";
    int key[] = {3, 19, 5, 7, 2, 14, 11, 11, 9, 4, 3, 12, 8};
    for (int i = 0; pt[i] != '\0'; i++) {
        char c = ((pt[i] - 'A') + key[i]) % 26 + 'A';
        printf("%c", c);
    }
    return 0;
}

