#include <iostream>

int a, b;  // Declare a and b outside of any function

void f1(int a, int b) {
    a = 3;
    b = 7;
    std::cout << a << " " << b << std::endl;
}

void f2() {
    a = 10;
    b = 20;
}

int main() {
    f1(a,b);
    f2();  // Call f2 to initialize a and b
    std::cout << a << " " << b << std::endl;  // Print the values of a and b
    return 0;  // Return 0 to indicate successful execution
}
