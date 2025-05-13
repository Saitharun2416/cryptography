#include <stdio.h>
#include <string.h>

#define MAX 1000

// Function to return decrypted character using substitution guess
char substitute(char ch) {
    switch (ch) {
        case ';': return 'e';  // Most frequent
        case '4': return 't';  // Common in "the"
        case ')': return 'h';  // Common in "the"
        case '5': return 'a';
        case '8': return 'o';
        case '+': return 'n';
        case '*': return 's';
        case '6': return 'r';
        case '0': return 'i';
        case '3': return 'l';
        case '1': return 'd';
        case '2': return 'u';
        case '9': return 'y';
        case '.': return 'm';
        case ':': return 'c';
        case '#': return 'g';
        case ']': return 'f';
        case '(': return 'w';
        case '?': return 'p';
        case '-': return 'v';
        default: return ch; // keep unchanged if unknown
    }
}

int main() {
    char cipher[MAX] = 
    "531305))6*;4826)4+.)4+);806*;48+860))85;;]8*;:+8+83 (88)5+;46(;88*96*7;8)(;485);5*+2:(;4956*2(5*-4)818*"
    "4069285);)618)41;1(#9;48081;8:841;48+85;4)4851528806*81 (19;48;(88;4(1?34;48)44;161;:188;17;";

    printf("Decrypted Message:\n\n");

    for (int i = 0; cipher[i] != '\0'; i++) {
        printf("%c", substitute(cipher[i]));
    }

    printf("\n");
    return 0;
}

