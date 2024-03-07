//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool sameFreq(string s)
{
    unordered_map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
    }
    int mn=INT_MAX,mx=INT_MIN;int cnt=0;
    for(auto it:mpp){
       
       mx=max(it.second,mx);
       mn=min(mn,it.second);
        }
    for(auto it:mpp){
        if(it.second==mx){
            cnt++;
        }
    }
    if(cnt>1 && mx-mn==1 )return 0;
    if(mx-mn==1 || mx-mn==0 ){
        return 1;
        }
    return 0;
} 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends