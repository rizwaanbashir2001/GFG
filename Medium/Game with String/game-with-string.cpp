//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            int idx = s[i]-'a';
            v[idx]++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(v[i]!=0) pq.push(v[i]);
        }
        while(k!=0){
            int tp = pq.top();
            pq.pop();
            k--;
            pq.push(tp-1);
        }
        int res = 0;
        while(!pq.empty()){
            int tp = pq.top();
            pq.pop();
            res += (tp*tp);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends