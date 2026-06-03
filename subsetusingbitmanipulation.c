#include <stdio.h>
#include <math.h>

// Function to print all subsets of a given set
void printSubsets(char set[], int n) {
    // Number of subsets is 2^n
    int totalSubsets = pow(2, n);
    
    // Loop through all possible subsets
    for (int i = 0; i < totalSubsets; i++) {
        printf("{ ");
        // Check each bit of the number
        for (int j = 0; j < n; j++) {
            // If j-th bit of i is set, include set[j] in the subset
            if (i & (1 << j)) {
                printf("%c ", set[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    // Example set
    char set[] = {'a', 'b', 'c'};
    int n = sizeof(set) / sizeof(set[0]);

    // Print all subsets
    printSubsets(set, n);

    return 0;
}
