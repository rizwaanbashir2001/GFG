//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{   
    
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    double M=-1;
    
    int signum(int a,int b){
        if(a==b){
            return 0;
        }
        else if(a>b){
            return 1;
        }
        return -1;
    }
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {   
        //a.push_back(x);
        switch(signum(maxi.size(),mini.size())){
            case 0: 
                if(x>M){
                   mini.push(x);
                   M=mini.top();
                }
                else{
                    maxi.push(x);
                    M=maxi.top();
                }
                break;
            
            case 1:
                if(x>M){
                    mini.push(x);
                    M=(maxi.top()+mini.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(x);
                    M=(maxi.top()+mini.top())/2;
                }
                break;
            case -1:
                if(x>M){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(x);
                    M=(maxi.top()+mini.top())/2;
                    
                }
                else{
                    maxi.push(x);
                    M=(maxi.top()+mini.top())/2;
                }
                break;   
        }
        
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
       return M;
    }
};



//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends