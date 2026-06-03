#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& arr, int median, int operations) {
    int n = arr.size();
    int count = 0;
    for (int i = n / 2; i < n; ++i) {
        if (arr[i] < median) {
            count += median - arr[i];
        }
    }
    return count <= operations;
}

int min_operations_to_increase_median(vector<int>& arr, int operations) {
    sort(arr.begin(), arr.end());
    int low = arr[arr.size() / 2];
    int high = 1e9 + 7;
    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, mid, operations)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
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
        int operations = (n + 1) / 2 - 1; // Number of operations required to increase the median
        cout << min_operations_to_increase_median(arr, operations) << endl;
    }
    return 0;
}
