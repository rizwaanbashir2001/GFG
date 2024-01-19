//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        
        vector<int> top(K + 1);
        vector<vector<int>> ans;
        
        unordered_map<int, int> freq;
        
        for (int m = 0; m < N; m++) {
            
            vector<int>temp;
            
            freq[arr[m]]++;
           
            top[K] = arr[m];
           
            auto it = find(top.begin(), top.end() - 1, arr[m]);
            
            for (int i = distance(top.begin(), it) - 1; i >= 0; --i) {
                
                if (freq[top[i]] < freq[top[i + 1]])
                    swap(top[i], top[i + 1]);
                
                else if ((freq[top[i]] == freq[top[i + 1]])
                         && (top[i] > top[i + 1]))
                    swap(top[i], top[i + 1]);
                else
                    break;
            }
         
            for (int i = 0; i < K && top[i] != 0; ++i)
                temp.push_back(top[i]);
               
            ans.push_back(temp);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends