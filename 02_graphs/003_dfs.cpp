#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int src, vector<int> &ans, const vector<int> adj[], vector<bool> &vis) {
        vis[src]=true;
        ans.push_back(src);
        
        for(int u: adj[src]){
            if(!vis[u]) {
                dfs(u, ans, adj, vis);
            }
        }
    }
        
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        vector<int> ans;
        dfs(0, ans, adj, vis);
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  