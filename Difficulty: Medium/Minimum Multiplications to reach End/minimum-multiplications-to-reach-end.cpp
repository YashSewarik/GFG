//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)return 0;
        int mod = 100000;
        vector<int> dist (mod,1e9);
        dist[start] = 0;
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty()){
            
            auto iter = q.front();
            q.pop();
            int no = iter.first;
            int steps = iter.second;
            for(int i=0;i<arr.size();i++){
                if(dist[(no*arr[i])%mod]>steps+1){
                    dist[(no*arr[i])%mod] = steps+1;
                    q.push({(no*arr[i])%mod,steps+1});
                }
            }
            
        }
        if(dist[end]==1e9)return -1;
        return dist[end];
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends