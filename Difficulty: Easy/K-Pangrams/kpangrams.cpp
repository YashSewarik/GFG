//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int size2=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!=' ')size2++;
        }
        int size1=str.size();
        if(size2<26)return false;
        unordered_set<char> us;
        for(auto a:str){
            us.insert(a);
        }
        int size = us.size();
        auto it = us.find(' ');
        
        if(it!=us.end()){
            if((27-size)<=k)return true;
        else return false;
        
        }
        else{
        if((26-size)<=k)return true;
        else return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends