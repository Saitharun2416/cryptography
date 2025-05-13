#include <stdio.h>
// Simplified ECB mode decryption outline
void ecb_decrypt(int ciphertext[], int decrypted[], int key[]) {
    // ECB decryption logic
}

int main() {
    int ciphertext[] = {0x01234567, 0x89abcdef};
    int key[] = {0x2b7e1516, 0x28aed2a6};
    int decrypted[2];
    
    ecb_decrypt(ciphertext, decrypted, key);
    
    // Output decrypted values
    printf("Decrypted text: ");
    for (int i = 0; i < 2; i++) {
        printf("%x ", decrypted[i]);
    }
    return 0;
}

