#include <bits/stdc++.h>
using namespace std;
#define maxvertices 100000
int numvertices, numedges, numconnectedcomponents;
int parent[maxvertices], rank[maxvertices];
void initializeunionfind()
{
    for (int i = 0; i < numvertices; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    numconnectedcomponents = numvertices;
}
int findroot(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;
    parent[vertex] = findroot(parent[vertex]);
    return parent[vertex];
}
void unionsets(int vertexu, int vertexv)
{
    int rootu = findroot(vertexu);
    int rootv = findroot(vertexv);
    if (rootu == rootv)
        return;
        --numconnectedcomponents;
        if(rank[rootu]<rank[rootv])
        {
            parent[rootu]=rootv;
        }
        else
        {
            parent[rootv]=rootu;
            if(rank[rootu]==rank[rootv])
            {
                rank[rootu]++;
            }
        }
}
#define maxedges 100000
int efgeu
int main()
{
}