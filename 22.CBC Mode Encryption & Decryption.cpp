#include <stdio.h>

void xor_bits(char *a, char *b, char *out, int n) {
    for (int i = 0; i < n; i++)
        out[i] = (a[i] - '0') ^ (b[i] - '0') + '0';
}

int main() {
    char iv[] = "10101010";
    char pt[] = "0000000100100011"; // 2 blocks of 8 bits
    char key[] = "01111110"; // Dummy key
    char ct1[9], ct2[9];

    xor_bits(iv, pt, ct1, 8); // First block XOR IV
    xor_bits(ct1, pt + 8, ct2, 8); // Second block XOR with next plaintext

    ct1[8] = '\0'; ct2[8] = '\0';
    printf("Encrypted Blocks: %s %s\n", ct1, ct2);
    return 0;
}

