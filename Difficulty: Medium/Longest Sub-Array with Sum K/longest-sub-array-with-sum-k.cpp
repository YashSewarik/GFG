//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        unordered_map<int,int> m;
        int ps = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            ps+=a[i];
            if(ps==k){
                res=i+1;
            }
            if(m.find(ps)==m.end()){
                m.insert({ps,i});
            }
            if(m.find(ps-k)!=m.end()){
                res = max(res,i-m[ps-k]);
            }
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends