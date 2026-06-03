#include <stdio.h>

// Function to print a row of stars
void printStars(int n) {
    if (n > 0) {
        printf("*");
        printStars(n - 1);
    }
}

// Function to print a right-angled triangle
void printTriangle(int n) {
    if (n > 0) {
        // Print the row of stars
        printStars(n);
        printf("\n");

        // Recursively print the smaller triangle
        printTriangle(n - 1);
    }
}

int main() {
    int height;

    // Input the height of the triangle
    printf("Enter the height of the right-angled triangle: ");
    scanf("%d", &height);

    // Print the right-angled triangle
    printTriangle(height);

    return 0;
}
