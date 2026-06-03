#include <iostream>
#include <vector>

using namespace std;

bool is_stable(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) { 
            for (int k = j + 1; k < arr.size(); ++k) { 
                if (!(arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[j] + arr[k] > arr[i])) {
                    return false;
                }
            }
        }
    }
    return true;
}
void find_partitions(const vector<int>& arr, int start, vector<vector<int>>& current_partition, vector<vector<vector<int>>>& partitions) {
    if (start == arr.size()) {
        if (current_partition.size() > 1) {  // At least two subsegments
            partitions.push_back(current_partition);
        }
        return;
    }

    for (int end = start; end < arr.size(); ++end) {
        vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
        if (is_stable(subarray)) {
            current_partition.push_back(subarray);
            find_partitions(arr, end + 1, current_partition, partitions);
            current_partition.pop_back();
        }
    }
}

bool has_at_least_two_different_partitions(const vector<vector<vector<int>>>& partitions) {
    if (partitions.size() < 2) {
        return false;
    }

    for (int i = 0; i < partitions.size(); ++i) {
        for (int j = i + 1; j < partitions.size(); ++j) {
            if (partitions[i].size() != partitions[j].size()) {
                return true;
            }
            for (int k = 0; k < partitions[i].size(); ++k) {
                if (partitions[i][k].size() != partitions[j][k].size()) {
                    return true;
                }
            }
        }
    }
    return false;
}

string solve(const vector<int>& arr) {
    vector<vector<vector<int>>> partitions;
    vector<vector<int>> current_partition;
    find_partitions(arr, 0, current_partition, partitions);

    return has_at_least_two_different_partitions(partitions) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << solve(arr) << endl;
    }

    return 0;
}