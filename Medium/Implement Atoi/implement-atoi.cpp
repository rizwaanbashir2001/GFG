//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int result = 0;
        int char_flag = 0;
        
        //check vaild string
        if(s.empty()){
            return -1;
        }
        
        // Handle the first character
        char val = s[0];
        if(val == '-'){
            char_flag = 1;
        }
        else if(val>='0' && val<='9'){
            result = val - '0';
        }
        else{
            return -1;
        }
        
        //Process the remaining characters
        
        for(size_t i=1;i<s.length();i++){
            val = s[i];
            if(val>='0' && val <='9'){
                result = result *10 + (val-'0');
            }
            else{
                return -1;
            }
        }
        
        return (char_flag == 1) ? -1 * result : result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends