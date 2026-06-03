// You are given an array of integers, and you need to support
// the following operations efficiently:
// Range Sum Query (RSQ): Given a range [L, R], find the
// sum of the elements in the array between indices L and R, inclusive.
// Point Update: Update the value of an element at a specific index i.

// Example Input and Output
// Input:

// Initial array: [1, 2, 3, 4, 5]
// Operations:
// RSQ(1, 3) -> Sum of elements from index 1 to 3.
// Update(2, 10) -> Change the element at index 2 to 10.
// RSQ(0, 4) -> Sum of elements from index 0 to 4.
// Output:

// RSQ(1, 3) = 2 + 3 + 4 = 9
// After Update(2, 10), array becomes [1, 2, 10, 4, 5].
// RSQ(0, 4) = 1 + 2 + 10 + 4 + 5 = 22.
#include <bits/stdc++.h>
using namespace std;
class sementtree
{
private:
    vector<int> tree;
    int n;
    void buildtree(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            // recursively buil the left and right subtrees
            buildtree(arr, leftChild, start, mid);
            buildtree(arr, rightChild, mid + 1, end);
            // build the current node
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
};

int main()
{
}