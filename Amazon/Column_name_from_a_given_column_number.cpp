// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans;
        while(n)
        {
            int val=0;
           
            if(n%26==0)
            {
                val=25;
                 n = (n / 26) - 1;
            }
            else
            {
                val=(n%26)-1;
                n/=26;
            }
            char ch='A'+val;
             //cout<<n%26<<" "<<ch<<endl;
            ans.push_back(ch);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends