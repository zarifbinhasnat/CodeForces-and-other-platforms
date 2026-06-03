#include <stdio.h>

void first() {
    printf("Hello\n");
}

void second() {
        first();

    printf("World\n");
    
}

int main() {
    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    
    printf("start\n");
    second();
    printf("End\n");
    return 0; 
}
