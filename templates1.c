#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;
        
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If we reach here, the element was not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binary_search(arr, n, target);
    
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *arr;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *da = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (da == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    da->arr = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (da->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    da->size = 0;
    da->capacity = INITIAL_CAPACITY;
    return da;
}

void resize(DynamicArray *da) {
    da->capacity *= 2;
    da->arr = realloc(da->arr, da->capacity * sizeof(int));
    if (da->arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void append(DynamicArray *da, int value) {
    if (da->size >= da->capacity) {
        resize(da);
    }
    da->arr[da->size++] = value;
}

void freeDynamicArray(DynamicArray *da) {
    free(da->arr);
    free(da);
}

int main() {
    DynamicArray *da = createDynamicArray();

    // Append some elements
    for (int i = 0; i < 20; i++) {
        append(da, i);
    }

    // Print the elements
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->arr[i]);
    }
    printf("\n");

    // Free the dynamic array
    freeDynamicArray(da);

    return 0;
}
