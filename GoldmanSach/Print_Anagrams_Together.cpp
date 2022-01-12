// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
         vector<vector<string>>ans(string_list.size());
        map<string,int>mp;
        int cnt=1;
        for(auto it:string_list){
            string temp=it;
            //cout<<it<<" "<<temp<<endl;
            sort(temp.begin(),temp.end());
            if(mp.find(temp) == mp.end())
            {
                mp[temp]=cnt++;
            }
           // cout<<mp[temp]-1<<endl;
            ans[mp[temp]-1].push_back(it);
            
            
            
        }
        vector<vector<string>>ans2(cnt-1);
        int j=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()==0)continue;
            for(auto it:ans[i])
            {
               ans2[j].push_back(it);
            }
            j++;
            //cout<<endl;
        }
        return  ans2;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends