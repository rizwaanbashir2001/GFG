//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n){
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) {
            if(gallery[i] == -1) continue;
            arr.push_back({max(0, i - gallery[i]), min(n-1, i + gallery[i])});
        }
        sort(arr.begin(), arr.end()); 
        int i = 0, cnt = 0, j = 0, sz = arr.size();
        while(i < n){
            if(arr[j].first > i) return -1;
            int prev_i = i;
            while(j < sz and arr[j].first <= prev_i) i = max(i, arr[j].second + 1), j++;
            cnt++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends