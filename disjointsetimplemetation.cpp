#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent; // Parent of each element
    vector<int> rank;   // Rank (or size) of each set

public:
    // Constructor: initializes n elements
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 1); // Initial rank of each set is 1
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find operation with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by rank/size
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX; // Attach smaller tree to larger tree
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX; // Arbitrarily choose one root
                rank[rootX]++;         // Increment rank
            }
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    // Print the parent array (for debugging)
    void printParents()
    {
        for (size_t i = 0; i < parent.size(); ++i)
        {
            cout << "Element " << i << ": Parent " << parent[i] << "\n";
        }
    }
};

int main()
{
    int n = 10; // Number of elements
    DisjointSet ds(n);

    // Perform some union operations
    ds.unionSets(1, 2);
    ds.unionSets(2, 3);
    ds.unionSets(4, 5);
    ds.unionSets(6, 7);
    ds.unionSets(5, 6);

    // Check connectivity
    cout << "1 and 3 connected: " << ds.isConnected(1, 3) << "\n";
    cout << "4 and 7 connected: " << ds.isConnected(4, 7) << "\n";
    cout << "3 and 5 connected: " << ds.isConnected(3, 5) << "\n";

    // Print the parent array
    ds.printParents();

    return 0;
}
