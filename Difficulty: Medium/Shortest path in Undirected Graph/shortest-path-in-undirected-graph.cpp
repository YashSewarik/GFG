//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  
  
  
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        vector<vector<int>> adj(n);
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> ans (n,1e9);
        ans[src] = 0;
        vector<int> vis(n,0);
        stack<int> st;
        
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(ans[it]>ans[node]+1){
                    ans[it] = ans[node] +1;
                    q.push(it);
                }
            }
            
            
        }
        for (int i = 0; i < n; i++) {
        if (ans[i] == 1e9) ans[i] = -1;
      }
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends