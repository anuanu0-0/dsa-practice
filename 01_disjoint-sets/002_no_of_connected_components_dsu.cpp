#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int rank1[100001];

class Solution
{
    int count = 0;
    int parent(int x, int par[]) {
        if (x==par[x]) return x;
        return parent(par[x], par);
    }
    
    public:
    void unionNodes( int a, int b, int par[], int rank[], int n) {
        if (n<=0) return;
        int a_rep = parent(a, par), b_rep = parent(b, par);
        if (a_rep == b_rep) return;
        if (rank[a_rep] > rank[b_rep]) par[b_rep] = a_rep;
        else if (rank[a_rep] < rank[b_rep]) par[a_rep] = b_rep;
        else {
            par[b_rep] = a_rep;
            rank[a_rep]++;
        }
        
        count++;
    }
    
    int findNumberOfConnectedComponents( int n, int par[], int rank[]) {
        /***
         * Other approach :-
         *      unordered_set<int>s;
         *       for(int i=1; i<=n; i++) {
         *           s.insert(parent(i, par));
         *       }
         *       return s.size();
         * ****/

        return n-count;
    }
};

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        int q;
        cin>>q;
        Solution obj;
        while(q--) {
            int a,b;
            cin>>a>>b;
            
            obj.unionNodes(a,b, arr, rank1, n);
        }

        cout<<obj.findNumberOfConnectedComponents(n, arr, rank1)<<endl;
    }
    return 0;
} 