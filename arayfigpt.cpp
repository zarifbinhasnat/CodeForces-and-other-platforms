#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool canBeSorted(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= 10) {
            int num = arr[i];
            while (num > 0) {
                int digit = num % 10;
                arr.insert(arr.begin() + i, digit);
                num /= 10;
            }
            arr.erase(arr.begin() + i + 1); // Remove the original element
        }
    }
    return isSorted(arr);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        if (canBeSorted(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
