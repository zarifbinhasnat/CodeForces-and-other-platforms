#include<bits/stdc++.h>
using namespace std;

// Function to reverse a number if it is greater than 10
int reverseIfGreaterThanTen(int num) {
    if (num > 10) {
        int reversed = 0;
        while (num != 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    } else {
        return num; // If the number is not greater than 10, return it unchanged
    }
}

// Function to check if a vector is in increasing order
bool isIncreasing(const vector<int>& vec) {
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        
        for(int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        if(isIncreasing(ar)) {
            cout << "YES";
            cout << endl;
            break;
        }
        else {
        vector<int> updated_ar;
        
        for(int i = 0; i < n; i++) {
            if(ar[i] > 10) {
                ar[i] = reverseIfGreaterThanTen(ar[i]); // Reverse the number if it is greater than 10
                int num = ar[i];
                while (num > 0) {
                    updated_ar.push_back(num % 10);
                    num /= 10; // Extract digits in reverse order like 45 will be 4 and 5
                }
            } else {
                updated_ar.push_back(ar[i]);
            }
        }
        
        // Check if the updated array is in increasing order
        if(isIncreasing(updated_ar)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;

    }
    }
    return 0;
}
