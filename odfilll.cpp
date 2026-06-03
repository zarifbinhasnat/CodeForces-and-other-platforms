#include <bits/stdc++.h>
using namespace std;
// take the input of the 2d vector
vector<vector<int>> oddFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {

queue<pair<int,int>> flood;
flood.push({sr, sc});
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n = grid.size();
if (n == 0) return grid;
int m = grid[0].size();
int origColor = grid[sr][sc];
if (origColor == newColor) return grid;

flood.push({sr, sc});
grid[sr][sc] = newColor;

while (!flood.empty())
{
    auto [x, y] = flood.front();
    flood.pop();
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != origColor)
            continue;
        grid[nx][ny] = newColor;
        flood.push({nx, ny});
    }
}
return grid;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    vector<vector<int>> result = oddFill(v, sr, sc, newColor);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}