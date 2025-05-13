#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate log base 2
double logBase2(long long num) {
    return log(num) / log(2);
}

int main() {
    // Total possible keys = 25! (factorial of 25)
    long long totalPossibleKeys = factorial(25);
    
    // Calculate the log base 2 of total possible keys
    double powerOf2 = logBase2(totalPossibleKeys);
    
    printf("Total possible keys for Playfair cipher: %lld\n", totalPossibleKeys);
    printf("Power of 2 approximation: %.2f\n", powerOf2);
    
    return 0;
}

