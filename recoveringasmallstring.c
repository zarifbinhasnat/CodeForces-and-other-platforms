#include<stdio.h>

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        char ar[4]; // Need space for null terminator '\0'
        scanf("%d", &n);
        if (n <= 26) {
            ar[0] = 'a';
            ar[1] = 'a';
            ar[2] = 'a' + n - 3;
            ar[3] = '\0'; // Null terminator to mark end of string
        } else if (n <= 26 * 2) {
            ar[0] = 'a';
            ar[1] = 'a' + (n  26) - 1;
            ar[2] = 'a' + (n - 26) - 1;
            ar[3] = '\0'; // Null terminator to mark end of string
        } else {
            ar[0] = 'a' + (n - 1) % 26;
            ar[1] = 'a' + (n  / 26) % 26;
            ar[2] = 'a' + ((n - 1) / (26 * 26)) % 26;
            ar[3] = '\0'; // Null terminator to mark end of string
        }
        printf("%s\n", ar);
    }
    return 0;
}
