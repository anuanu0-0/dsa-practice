#include <bits/stdc++.h>
using namespace std;

/******************
 ******** DFS
 ******************/

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

void dfs(int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &grid)
{
    if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1 && grid[x][y] == '1' && !vis[x][y])
    {
        vis[x][y] = true;
        for (int k = 0; k < 8; k++)
        {
            dfs(x + dx[k], y + dy[k], n, m, vis, grid);
        }
    }
    return;
}

// Function to find the number of islands.
int numIslands_dfs(vector<vector<char>> &grid)
{
    int counter = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                dfs(i, j, n, m, vis, grid);
                counter++;
            }
        }
    }

    return counter;
}

/******************
 ******** BFS
 ******************/

vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};

bool isValid(int x, int y, int n, int m) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int numIslands_bfs(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and grid[i][j] == '1') {
                ans++;
                vis[i][j] = true;

                q.push({i, j});
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 8; k++) {
                        if (isValid(x + dx[k], y + dy[k], n, m) and !vis[x + dx[k]][y + dy[k]] and grid[x + dx[k]][y + dy[k]] == '1') {
                            q.push({x + dx[k], y + dy[k]});
                            vis[x + dx[k]][y + dy[k]] = true;
                        }
                    }
                }
            }
        }
    }

    return ans;
}