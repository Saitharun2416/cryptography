#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int n = 3599, e = 31;
    int p = 59, q = 61; // Found by factoring
    int phi = (p - 1) * (q - 1); // phi = 3480
    int x, y;

    gcdExtended(e, phi, &x, &y);
    int d = (x % phi + phi) % phi;

    printf("Private key d = %d\n", d);
    return 0;
}

