#include<bits/stdc++.h>
using namespace std;

int parent(int i, int par[]) {
    while(i!=par[i]) {
        i = par[i];
    }
    return i;
}

void union_( int a, int b, int par[], int rank[]) {
    int x = parent(a, par);
    int y = parent(b, par);

    if(x==y) {
        return;
    }

    if(rank[x]>=rank[y]) {
        rank[x]++;
        par[y] = par[x];
    } else {
        rank[y]++;
        par[x] = par[y];
    }
    return;
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) 
{
	
	pair<long long int, pair<int, int>> wt[2*m];
	int par[n+1], rank[n+1];
	
	for (int i=1; i<=n; i++) {
	    par[i]=i;
	    rank[i]=1;
	}
	 
	 int k = 0;
	 
	 for(int i=1; i<=n; i++) {
	     for (int j=0; j<adj[i].size(); j++) {
	         wt[k++] = make_pair(adj[i][j].second, make_pair(i, adj[i][j].first));
	     }
	 }
	 
	 sort(wt, wt+k);
	 long long mst = 0;
	 
	 for (int i=0; i<k; i++) {
	     int u = wt[i].second.first;
	     int v = wt[i].second.second;
	     long long wt1 = wt[i].first;
	     
	     if (parent(u, par) != parent(v, par)) {
	         union_(u, v, par, rank);
	         mst += wt1;
	     }
	 }

    return mst;
}

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
