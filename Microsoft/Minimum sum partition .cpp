// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:

    int Recursion(int idx,int arr[],vector<vector<int>>&dp,int sum1,int sum2)
    {
        if(idx==dp.size())
        {
            return abs(sum1-sum2);
        }
        if(dp[idx][sum1]!=-1)return dp[idx][sum1];
        //if(dp[idx][sum2]!=-1)return dp[idx][sum2];
        int diff1=Recursion(idx+1,arr,dp,sum1+arr[idx],sum2);
        int diff2=Recursion(idx+1,arr,dp,sum1,sum2+arr[idx]);
        return dp[idx][sum1]=min(diff1,diff2);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
        int sum=0;
        
        for(int i=0;i<n;i++)sum+=arr[i];
     
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return Recursion(0,arr,dp,0,0);
	} 
};


// { Driver Code Starts.
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
}  // } Driver Code Ends