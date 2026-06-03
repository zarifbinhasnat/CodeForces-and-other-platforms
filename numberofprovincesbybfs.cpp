#include <bits/stdc++.h>
using namespace std;
class Soln
{
private:
    void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int currently_pprocessing = q.front();
            for (int neightbor : adj[currently_pprocessing])
            {
                if (!visited[neightbor])
                {
                    visited[neightbor] = true;
                    q.push(neightbor);
                }
            }
        }
    }

    void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
    {
        stack<int> st;
        st.push(start);
        visited[start] = true;

        while (!st.empty())
        {
            int current = st.top();
            st.pop();

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }
    }

public:
    int findProvinces(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                bfs(i, adj, visited);
                ++provinces;
            }
        }
        return provinces;
    }
};
int main()
{
    
}