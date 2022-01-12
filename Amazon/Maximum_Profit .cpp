// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>>dp(K+1,vector<int>(N+1,0));
        for(int i=1;i<=K;i++)
        {
            for(int j=1;j<N;j++)
            {
                int val=INT_MIN;
                for(int m=0;m<j;m++)
                {
                    val=max(val,A[j]-A[m]+dp[i-1][m]);
                }
                dp[i][j]=max(val,dp[i][j-1]);
            }
        }
        return dp[K][N-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends