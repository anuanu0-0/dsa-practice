#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int parent(int x, int par[]) {
        if(x==par[x]) return x;
        return parent(par[x], par);
    }
    
    /***
     * Union: Join two subsets into a single set.
     * ***/
    public:
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int x = parent(a, par), y = parent(b, par);
        if (rank1[x] > rank1[y]) par[y] = x;
        else if (rank1[y] > rank1[x]) par[x] = y;
        else {
            par[y] = x;
            rank1[x]+=1;
        }
    }
    
    /****
     * isConnected: Determine which subset a particular element is in. 
     * This can be used for determining if two elements are in same subset.
     * ***/
    bool isConnected(int x,int y, int par[], int rank1[]) {
        return parent(x, par)==parent(y,par);
    }
};


int main() {
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
            
        int par[n+1];
        int rank1[n+1];

        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }

    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
