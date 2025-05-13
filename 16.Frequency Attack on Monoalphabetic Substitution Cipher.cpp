#include <stdio.h>
char guess_sub(char c) {
    // Sample guessed mapping (simplified)
    switch(c) {
        case 'Q': return 'E';
        case 'W': return 'T';
        case 'X': return 'A';
        default: return c;
    }
}
int main() {
    char ct[] = "QWXWQQ";
    for (int i = 0; ct[i]; i++)
        printf("%c", guess_sub(ct[i]));
    return 0;
}

