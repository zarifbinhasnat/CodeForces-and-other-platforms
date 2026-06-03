#include <iostream>
#include <string>

int main() {
    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    std::string line;

    // Read a line from standard input
    std::getline(std::cin, line);

    // Do something with the line
    std::cout << "You entered: " << line << std::endl;

    return 0;
}
