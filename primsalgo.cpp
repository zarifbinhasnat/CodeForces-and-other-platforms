#include <bits/stdc++.h>
using namespace std;
int minKey(vector<int> &key, vector<bool> &mstSet)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
}
void primMST(vector<vector<int>> &graph)
{
    int v = graph.size();

    vector<int> parent(v);  // array to store the constructed mst
    vector<int> key(v);     // key values used to pick minimum weight edge in cut
    vector<bool> mstSet(v); // to represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < v; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;
    // the mst will have v vertices
    for (int count = 0; count < v - 1; count++)
    {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < v; v++)

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}
}
int main()
{
}