// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void print(int start, int end,vector<vector<int>>&bracket,char& name,string &ans)
    {
   
        if (start == end) {
           ans+=name++;
            return;
        }

        ans+="(";

 
        print(start,bracket[start][end],bracket, name,ans);

   
        print(bracket[start][end] + 1, end,bracket, name,ans);
        ans+= ")";
    }
    int Recursion( int st[],int start,int end, vector<vector<int>>&dp,vector<vector<int>>&bracket)
    {
        if(start==end)
        {
            return 0;
        }
        if(dp[start][end]!=-1)return dp[start][end];
       
        dp[start][end]=INT_MAX;     
        for(int i=start;i<end;i++)
        {
            
            int cnt=(st[start-1]*st[end]*st[i]) + 
                              Recursion(st,start,i,dp,bracket)+
                                Recursion(st,i+1,end,dp,bracket);
            if(cnt<dp[start][end])
            {
                dp[start][end]=cnt;
                bracket[start][end]=i;
            }
           
                
        }
        return dp[start][end];
    }
    string matrixChainOrder(int p[], int n){
        // code here
         vector<vector<int>>dp(n,vector<int>(n,-1));
         vector<vector<int>>bracket(n,vector<int>(n,-1));
         Recursion(p,1,n-1,dp,bracket);
         char ch='A';
         string ans="";
         print(1,n-1,bracket, ch,ans);
         return ans;
         
         
        
       
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends