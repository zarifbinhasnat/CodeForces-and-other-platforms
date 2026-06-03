#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> segTree; // The segment tree array
    int n;

    // Helper function to build the tree
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            segTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively build the left and right subtrees
            buildTree(arr, leftChild, start, mid);
            buildTree(arr, rightChild, mid + 1, end);

            // Internal node stores the sum of left and right children
            segTree[node] = segTree[leftChild] + segTree[rightChild];
        }
    }

    // Helper function for range sum query
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            // Range completely outside the current segment
            return 0;
        }
        if (l <= start && r >= end) {
            // Range completely inside the current segment
            return segTree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = query(leftChild, start, mid, l, r);
        int rightSum = query(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

    // Helper function for point update
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Update the value at the leaf node
            segTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                // Update the left child
                update(leftChild, start, mid, idx, value);
            } else {
                // Update the right child
                update(rightChild, mid + 1, end, idx, value);
            }

            // Recalculate the current node value
            segTree[node] = segTree[leftChild] + segTree[rightChild];
        }
    }

public:
    // Constructor to build the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    // Query public function
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    // Update public function
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

// Driver function to demonstrate the segment tree
int main() {
     freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    // Range sum query [1, 3]
    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    // Update index 1 to 10
    segTree.update(1, 10);
    cout << "After updating index 1 to 10:" << endl;

    // Range sum query [1, 3]
    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    return 0;
}
