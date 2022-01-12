// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int n)
    {
        // your code here
        int cnt=0;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            //if(i-1>=0)dp[i]+=dp[i-1];
            if(i-2>=0)dp[i]+=1+dp[i-2];
            //cout<<dp[i]<<" ";
        }
       // cout<<endl;
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends