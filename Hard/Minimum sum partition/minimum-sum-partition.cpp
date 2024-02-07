//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
        int sum = accumulate(arr, arr + n, 0);
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, 0));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= sum; j++) {
                if(j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
                else if(j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        int mn = INT_MAX;
       for(int j = 0; j <= sum / 2; j++)
            if(dp[n][j] == true)
                mn = min(mn, sum - (2 * j));
       return mn;
    }  
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends