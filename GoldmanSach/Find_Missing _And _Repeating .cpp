-// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int x=0;
        int *ans=new int[2];
        vector<int>vis(n+1,1);
        for(int i=0;i<n;i++)
        {
            x^=(i+1);
            x^=arr[i];
            vis[arr[i]]=0;
            
            
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                ans[1]=i;
                ans[0]=i^x;
                return ans;
                
            }
            
            
        }
        //int a=xor^temp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends