#include <bits/stdc++.h>
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

    // Get the number of unique ultimate parents
    int countUniqueParents()
    {
        unordered_set<int> uniqueParents;
        for (int i = 0; i < parent.size(); ++i)
        {
            uniqueParents.insert(find(i));
        }
        return uniqueParents.size();
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionSets(i, j);
                }
            }
        }

        return ds.countUniqueParents();
    }
};
int main()
{
}