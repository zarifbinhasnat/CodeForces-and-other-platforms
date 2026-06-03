#include <iostream>
#include <vector>
#include <string>

int main() {
    long long t;
    std::cin >> t;

    for (long long c = 0; c < t; ++c) {
        long long n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::vector<long long> replacementPositions;
        
        for (const std::string& substr : {"mapie", "pie", "map"}) {
            size_t pos = 0;
            while ((pos = s.find(substr, pos)) != std::string::npos) {
                s[pos + substr.length() / 2] = '?';
                replacementPositions.push_back(pos + substr.length() / 2);
                pos += substr.length();
            }
        }
        
        std::cout << replacementPositions.size() << std::endl;
    }

    return 0;
}
