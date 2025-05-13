#include <stdio.h>

void xor_with_counter(char *counter, char *plaintext, char *out, int n) {
    for (int i = 0; i < n; i++) {
        out[i] = (plaintext[i] - '0') ^ (counter[i] - '0') + '0';
    }
}

int main() {
    char counter[] = "00000000";
    char pt[] = "0000000100000010"; // Two 8-bit blocks
    char out1[9], out2[9];
    xor_with_counter(counter, pt, out1, 8);

    // Increment counter
    counter[7] = '1';
    xor_with_counter(counter, pt + 8, out2, 8);

    out1[8] = '\0'; out2[8] = '\0';
    printf("Ciphertext Blocks: %s %s\n", out1, out2);
    return 0;
}

