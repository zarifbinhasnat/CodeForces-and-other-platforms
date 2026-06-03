#include <cstdio>
#include <cstring>

using namespace std;

// Maximum number of vertices in the graph
#define MAX_VERTICES 100000

// Union-Find (Disjoint Set Union) data structures
int numVertices, numEdges, numConnectedComponents;
int parent[MAX_VERTICES], rank[MAX_VERTICES];

// Initialize the Union-Find structure
void initializeUnionFind() {
    // Set each vertex as its own parent and initialize ranks to 0
    for (int i = 0; i < numVertices; ++i) {
        parent[i] = i;  // Each vertex is initially its own parent
        rank[i] = 0;    // Initial rank is 0
    }
    // Initially, the number of connected components is equal to the number of vertices
    numConnectedComponents = numVertices;
}

// Find the root (representative) of a vertex with path compression
int findRoot(int vertex) {
    // If the vertex is its own parent, return it
    if (parent[vertex] == vertex) return vertex;
    // Otherwise, recursively find the root and apply path compression
    parent[vertex] = findRoot(parent[vertex]);
    return parent[vertex];
}

// Union operation: Combine two sets if they are disjoint
void unionSets(int vertexU, int vertexV) {
    // Find the roots (representatives) of the two vertices
    int rootU = findRoot(vertexU);
    int rootV = findRoot(vertexV);

    // If both vertices belong to the same set, no need to union
    if (rootU == rootV) return;

    // Decrease the count of connected components since two sets are merging
    --numConnectedComponents;

    // Union by rank to maintain a balanced tree structure
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;  // Make rootV the parent of rootU
    } else {
        parent[rootV] = rootU;  // Make rootU the parent of rootV
        if (rank[rootU] == rank[rootV]) {
            ++rank[rootU];  // Increment rank of rootU if ranks were equal
        }
    }
}

// Maximum number of edges in the graph
#define MAX_EDGES 100000

// Edge endpoints
int edgeU[MAX_EDGES], edgeV[MAX_EDGES];
// Number of queries and their indices
int numQueries, queryIndices[MAX_EDGES];
// Answers to the queries
int queryResults[MAX_EDGES];
// Track whether an edge is initially added to the graph
bool isEdgeAdded[MAX_EDGES];

int main() {
    // Input: Number of vertices and edges
    scanf("%d %d", &numVertices, &numEdges);

    // Input: Edges (u, v)
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d", &edgeU[i], &edgeV[i]);
    }

    // Input: Number of queries
    scanf("%d", &numQueries);

    // Mark all edges as added initially
    memset(isEdgeAdded, true, sizeof(isEdgeAdded));

    // Input: Indices of edges to be removed in queries
    for (int i = 0; i < numQueries; ++i) {
        scanf("%d", &queryIndices[i]);
        // Convert to 0-based indexing and mark these edges as not added
        isEdgeAdded[--queryIndices[i]] = false;
    }

    // Initialize Union-Find structure
    initializeUnionFind();

    // Add all edges that are not marked for removal
    for (int i = 0; i < numEdges; ++i) {
        if (!isEdgeAdded[i]) continue;  // Skip edges marked for removal
        unionSets(edgeU[i], edgeV[i]); // Union the endpoints of the edge
    }

    // Process queries in reverse order
    for (int i = numQueries - 1; i >= 0; --i) {
        // Record the current number of connected components
        queryResults[i] = numConnectedComponents;
        // Add the edge back to the graph
        unionSets(edgeU[queryIndices[i]], edgeV[queryIndices[i]]);
    }

    // Output: Results of the queries
    printf("%d", queryResults[0]);
    for (int i = 1; i < numQueries; ++i) {
        printf(" %d", queryResults[i]);
    }
    printf("\n");

    return 0;
}
