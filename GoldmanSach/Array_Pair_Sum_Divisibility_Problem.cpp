// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int>store(k,0);
        for(int i=0;i<nums.size();i++)
        {
            nums[i]%=k;
            store[nums[i]]++;
        }
        // for(auto it:store)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        if(store[0]%2)
        {
            return false;
        }
        for(int i=1;i<k;i++)
        {
            int val=k-i;
            if(i==val)
            {
                if(store[i]%2)
                {
                 return false;
                 }
                 continue;
                
            }
            if(store[i]!=store[val])
            {
                return false;
            }
        
        }
        return true;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends