#include <stdio.h>
int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int pt[2] = {'H'-'A', 'I'-'A'};  // Plaintext "HI"
    int ct[2];
    ct[0] = (key[0][0]*pt[0] + key[0][1]*pt[1]) % 26;
    ct[1] = (key[1][0]*pt[0] + key[1][1]*pt[1]) % 26;
    printf("Cipher: %c%c\n", ct[0]+'A', ct[1]+'A');
    return 0;
}

