//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    map<int,int> m;
    map<int,int> mt;
    int ptime = 0;   // Keeps the count of time 
    int max_size = 0;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        max_size = cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        ptime++;
        if (m.find(key) != m.end()) {
            mt[key] = ptime;
            return m[key];
        } 
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        ptime++;
        int mintime = INT_MAX;
        if (m.size() == max_size && m.find(key) == m.end()) {
        // If the size of cache is full, we find the least recently used key from the map and delete it
            map<int,int>::iterator minit;
            for (auto it = m.begin(); it != m.end(); it++) {
                if (mt[it->first] < mintime) {
                    mintime = mt[it->first];
                    minit = it;
                }
            }
            m.erase(minit);
        }
        m[key] = value;
        mt[key] = ptime;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends