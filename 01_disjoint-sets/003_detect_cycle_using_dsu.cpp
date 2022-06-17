#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int parent(int x, int par[]) {
        if (x==par[x]) {
            return x;
        }
    
        return parent(par[x], par);
    }
    
    bool _union (int a, int b, int par[], int rank[]) {
        int x = parent(a, par), y = parent(b, par);

        if(x==y) {
            return true;
        }
        
        if (rank[x] > rank[y]) par[y] = x;
        else if (rank[y] > rank[x]) par[x] = y;
        else {
            par[y] = x;
            rank[x]+=1;
        }
        return false;
    }
    
    public:
	int detectCycle(int v, vector<int>adj[])
    {
        int par[v];
        int rank[v];
        for(int i=0; i<v; i++) {
            par[i]=i;
            rank[i]=1;
        }
        
        bool isCycle = false;
        for(int i=0;i<v;i++) {  
	        for(int j=0;j<adj[i].size();j++) {
	            if (adj[i][j]>i) {
    	            isCycle = _union(i, adj[i][j], par, rank);
    	            if (isCycle) {
    	                return 1;
    	            }    
	            }
	        }
	    }
	   
	   return 0;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  