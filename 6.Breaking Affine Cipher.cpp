#include <stdio.h>

// Function to find modular inverse of a under mod 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    // Most frequent ciphertext letters: B = 1, U = 20
    // Assuming they correspond to E = 4 and T = 19
    int plain1 = 4;   // E
    int plain2 = 19;  // T
    int cipher1 = 1;  // B
    int cipher2 = 20; // U

    int a, b, found = 0;

    for (a = 1; a < 26; a++) {
        if (modInverse(a, 26) == -1) continue; // Skip if no modular inverse

        for (b = 0; b < 26; b++) {
            int enc1 = (a * plain1 + b) % 26;
            int enc2 = (a * plain2 + b) % 26;

            if (enc1 == cipher1 && enc2 == cipher2) {
                printf("Possible keys found: a = %d, b = %d\n", a, b);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No valid keys found.\n");

    return 0;
}

