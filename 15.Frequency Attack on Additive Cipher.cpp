#include <stdio.h>
#include <string.h>
void decrypt(char* text, int key) {
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", ((text[i]-'A'-key+26)%26)+'A');
        else
            printf("%c", text[i]);
    }
    printf("\n");
}
int main() {
    char ct[] = "WKLVLVDWHVW"; // "THISISATEST" with key 3
    for (int k = 0; k < 10; k++) {
        printf("Key %d: ", k);
        decrypt(ct, k);
    }
    return 0;
}

