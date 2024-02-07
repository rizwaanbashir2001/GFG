//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Recursive function with memoization to find the minimum cuts
    int solveMem(string str, int i, int n, vector<int> &dp) {
        // Base case: if the substring is empty, return 0
        if (i == n)
            return 0;

        // If the result for this substring is already calculated, return it
        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        // Iterate over all possible partitions of the substring
        for (int j = i; j < n; j++) {
            // If the substring [i, j] is a palindrome, calculate the result for the remaining substring
            if (isPalindrome(str, i, j)) {
                int ans = 1 + solveMem(str, j + 1, n, dp);
                mini = min(ans, mini);
            }
        }

        // Memoize the result for this substring and return
        return dp[i] = mini;
    }

    // Function to find the minimum cuts for palindromic partitioning
    int palindromicPartition(string str) {
        int n = str.length();

        // Create a memoization array to store computed results for substrings
        vector<int> dp(n + 1, -1);

        // Call the recursive function with memoization
        return solveMem(str, 0, n, dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends