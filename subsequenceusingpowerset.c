#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate all subsequences of a set
void generate_subsequences(int arr[], int n) {
    int num_subsequences = pow(2, n);

    // Iterate through all possible combinations
    for (int i = 0; i < num_subsequences; i++) {
        printf("{ ");
        // Print elements of the current subsequence
        for (int j = 0; j < n; j++) {
            // Check if jth bit in the binary representation of i is set
            if (i & (1 << j)) {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Subsequences:\n");
    generate_subsequences(arr, n);

    return 0;
}
