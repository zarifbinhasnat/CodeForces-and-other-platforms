#include <stdio.h>

#define MAX_ELEMENTS 101

int main() {
    
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int frequency[MAX_ELEMENTS] = {0};

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            frequency[num]++;
        }

        int found = 0;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (frequency[i] >= k) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("%d\n", k - 1);
        } else {
            printf("%d\n", n);
        }
    }

    return 0;
}
