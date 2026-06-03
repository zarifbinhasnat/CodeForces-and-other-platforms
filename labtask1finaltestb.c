#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    unsigned int n;
    scanf("%d", &n);
    
    char s;
    scanf(" %c", &s); // Notice the space before %c
    
    int digit;
    scanf("%d", &digit);
    
    if (s == 'L') {
        unsigned int add = n / (unsigned int)pow(10, digit);
        n = (n << digit) + add; // Parentheses added for clarity
    }
    else if (s == 'R') {
        unsigned int adder = n % (unsigned int)pow(10, digit);
        adder = adder * (unsigned int)pow(10, digit); // Simplified the calculation
        n = (n >> digit) + adder; // Parentheses added for clarity
    }
    
    printf("%u", n);
    return 0;
}
