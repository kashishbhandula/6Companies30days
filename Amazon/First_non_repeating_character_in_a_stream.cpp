// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>vis(26,0);
		    vector<char>store;
		    string ans="";
		    for(auto it:A)
		    {
		        vis[it-'a']++;
		        if(vis[it-'a']==1)
		        {
		             store.push_back(it);
		        }
		        else if(vis[it-'a']==2)
		        {
		            int i=0;
		            for(;i<store.size();i++)
		            {
		                if(store[i]==it)
		                {
		                    store.erase(store.begin()+i);
		                    break;
		                }
		            }
		           
		        }
		        if(store.size()==0)
		        {
		            ans+="#";
		        }
		        else
		        {
		            ans+=store[0];
		        }
		        
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends