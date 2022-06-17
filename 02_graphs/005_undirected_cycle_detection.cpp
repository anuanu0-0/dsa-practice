#include <bits/stdc++.h>
using namespace std;

/******************
 ******** DFS
 ******************/

bool dfs(int cur, int par, vector<int> &vis, const vector<int> adj[])
{
    vis[cur] = true;
    for (int nbr : adj[cur])
    {
        if (!vis[nbr])
        {
            if (dfs(nbr, cur, vis, adj))
                return true;
        }
        else if (nbr != par)
        {
            return true;
        }
    }

    return false;
}

bool isCycle_dfs(int V, vector<int> adj[])
{
    vector<int> vis(V, false);
    bool ans = false;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i] and dfs(i, -1, vis, adj))
            return true;
    }
    return false;
}

/******************
 ******** BFS
 ******************/

bool BFS(vector<int> adj[], vector<bool> &visited, int src) {
    // node, parent
    queue<pair<int, int>> q;

    q.push({src, -1});
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (int &u : adj[node]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push({u, node});
            } else if (u != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (BFS(adj, visited, i)) {
                return true;
            }
        }
    }
    return false;
}
