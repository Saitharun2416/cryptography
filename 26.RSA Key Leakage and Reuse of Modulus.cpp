#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

int main() {
    // Sample input
    int p = 7;
    int q = 11;
    int leaked_d = 43;
    int e2 = 13;

    // Computations
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int d2 = modInverse(e2, phi);

    // Output
    printf("=== Input ===\n");
    printf("p = %d, q = %d\n", p, q);
    printf("Leaked private key (d) = %d\n", leaked_d);
    printf("New public key component (e2) = %d\n\n", e2);

    printf("=== Output ===\n");
    printf("Modulus (n) = %d\n", n);
    printf("Euler's totient (f(n)) = %d\n", phi);
    printf("New private key (d2) = %d\n", d2);
    printf("Since f(n) can be computed from leaked d, reusing n is insecure.\n");

    return 0;
}

