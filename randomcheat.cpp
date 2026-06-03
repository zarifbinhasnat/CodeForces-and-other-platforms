using LL = long long;
using PLL = pair;
using TLLL = tuple;
using Neighbor = PLL;
node, weight using Graph = vector > ;
void mstPrim(Graph &graph, vector &dist, vector &parent)
{
    int n = graph.size();
    priority_queue, greater > pq; // weight, node, parent pq.push({0, 0, -1}); while(!pq.empty()) { auto [d1, x, p] = pq.top(); pq.pop(); if(dist[x] != -1) continue; dist[x] = d1; parent[x] = p; for(auto [y, d2]: graph[x]) { if(dist[y] != -1) continue; pq.push({d2, y, x}); } } }