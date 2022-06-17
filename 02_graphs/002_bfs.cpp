#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            bfs.push_back(u);
            
            for(int v: adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        
        return bfs;
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
        }
   
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  