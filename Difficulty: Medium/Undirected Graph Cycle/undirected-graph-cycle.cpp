//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool help(int s,vector<int> adj[],vector<int>& vis){
        queue<pair<int,int>>q;
        q.push({s,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(it!=parent){
                    if(!vis[it]){
                        vis[it]++;
                        q.push({it,node});
                    }
                    else{
                        return true;
                    }
                }
                
                
            }
        }
        return false;
    }
    
    bool dfshelp(int s,int p,vector<int> adj[],vector<int>& vis){
        vis[s]++;
        
        for (auto it : adj[s]) {
            if (!vis[it]) {
                if (dfshelp(it, s, adj, vis)) {
                    return true;  
                }
            } else if (it != p) {
                return true;  
            }
        }
        return false;
    }

    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                // if(help(i,adj,vis)){
                //     return true;
                // }
                if(dfshelp(i,-1,adj,vis))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends