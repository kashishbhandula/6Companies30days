// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int mod=1000000007;
		    int n=str.length();
		    int dp[n+1];
		    dp[0]=1,dp[1]=1;
		    if(str[0]=='0')return 0;
		    for(int i=1;i<=n;i++)
		    {
		        dp[i]=0;
		        if(str[i-1]>'0')
		        {
		            dp[i]=dp[i-1];
		        }
		        if (str[i-2] == '1' || (str[i-2] == '2' && str[i-1] < '7') )dp[i] += dp[i-2];
		        dp[i]%=mod;
		    }
		    return dp[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends