// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
		long long int dp[10002];
		bool flag=true;
	void fun()
	{
	    
	   	long long int elem2=2,elem3=3,elem5=5;
	     long long int pos2=0,pos3=0,pos5=0;
	     dp[0]=1;
	      long long int temp=1;
	     for(int i=1;i<10002;i++)
	     {
	         temp=min({elem2,elem3,elem5});
	         dp[i]=temp;
	       if(elem2==temp)
	         {
	             pos2++;
	             
	             elem2=dp[pos2]*2;
	             
	             
	         }
	         if(elem3==temp)
	         {
	             pos3++;
	              elem3=dp[pos3]*3;
	               
	         }
	         if(elem5==temp)
	         {
	             pos5++;
	             elem5=dp[pos5]*5;
	              
	         }
	     }
	}

	ull getNthUglyNo(int n) {
	   if(flag)
	   {
	       flag=!flag;
	       fun();
	   }
	   //  for(int i=0;i<=n;i++)
	   //  {
	   //      cout<<dp[i]<<" ";
	   //  }
	   //  cout<<endl;
	    return dp[n-1];
	    
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends