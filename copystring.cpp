task 7 : #include <iostream>
#include <string>
#include <vector>

using namespace std;

// Rabin-Karp algorithm use kore repeated DNA sequences ber korbe rolling hash diye, unordered sets chara
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    vector<long long> seen;  // Seen hashes track korar jonno vector
    vector<long long> repeated; // Repeated hashes track korar jonno vector
    int n = s.length();

    if (n < 10) return result;  // Jodi length 10 er kom hoy, tahole kono sequence toiri kora jabe na

    // Hashing er jonno constants
    const long long base = 31;   // Hash function er jonno ekta prime base
    const long long mod = 1e9 + 7;  // Ekta boro prime modulus

    // Prothom 10-letter sequence er hash calculate kora
    long long hash = 0;
    long long basePower = 1;  // base^10 % mod store kora

    // Prothom 10 characters er hash calculate kora
    for (int i = 0; i < 10; ++i) {
        hash = (hash * base + s[i]) % mod;
        if (i < 9) basePower = (basePower * base) % mod;  // base^9 % mod
    }

    seen.push_back(hash);  // Prothom sequence er hash seen vector e add kora

    // Baki sequences er jonno rolling hash apply kora
    for (int i = 10; i < n; ++i) {
        // Leftmost character er contribution remove kora ar rightmost character add kora
        hash = (hash - (s[i - 10] * basePower) % mod + mod) % mod;  // Positive thakbe eta ensure kora
        hash = (hash * base + s[i]) % mod;  // New character add kora

        // Check kora j hash ta already seen vector e ache kina
        bool found = false;
        for (long long h : seen) {
            if (h == hash) {
                found = true;
                break;
            }
        }

        // Jodi already dekha hash hoy, tahole repeated sequences e add kora
        if (found) {
            bool isAlreadyAdded = false;
            for (long long h : repeated) {
                if (h == hash) {
                    isAlreadyAdded = true;
                    break;
                }
            }
            if (!isAlreadyAdded) {
                repeated.push_back(hash);  // Repeated e add kora jodi age add na hoy
                result.push_back(s.substr(i - 9, 10));  // Actual sequence store kora
            }
        } else {
            seen.push_back(hash);  // Na hole, hash ta seen vector e add kora
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;  // DNA sequence input kora

    vector<string> repeatedSequences = findRepeatedDnaSequences(s);

    for (const string& seq : repeatedSequences) {
        cout << seq << ", ";  // Repeated sequences print kora
    }
    cout << endl;

    return 0;
}