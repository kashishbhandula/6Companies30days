// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool uniqueRow(vector<vector<int>> mat)
    {
        for(int i=0;i<9;i++)
        {
            bool vis[10];
             memset(vis, false,sizeof(vis));
            for(int j=0;j<9;j++)
            {
            
                if(mat[i][j])
                {
                    if(vis[mat[i][j]])return false;
                    vis[mat[i][j]]=true;
                }
            }
        }
        return true;
    }
    bool uniqueCol(vector<vector<int>> mat)
    {
        for(int i=0;i<9;i++)
        {
            bool vis[10];
             memset(vis, false,sizeof(vis));
            for(int j=0;j<9;j++)
            {
            
                if(mat[j][i])
                {
                    if(vis[mat[j][i]])return false;
                    vis[mat[j][i]]=true;
                }
            }
        }
        return true;
        
    }
    bool uniqueBlock(vector<vector<int>> mat)
    {
        for(int i=0;i<7;i+=3)
        {
            for(int j=0;j<7;j+=3)
            {
               
                bool vis[10];
                memset(vis, false,sizeof(vis));
                for(int k=i;k<i+3;k++)
                {
                    //vector<bool>vis(10,false);
                    for(int l=j;l<j+3;l++)
                    {
            
                        if(mat[k][l])
                        {
                            if(vis[mat[k][l]])return false;
                            vis[mat[k][l]]=true;
                        }
                    } 
                }
                
            }
            
        }
        return true;
        
    }
    int isValid(vector<vector<int>> mat){
        // code here
        
        if(uniqueCol(mat)&&uniqueRow(mat)&&uniqueBlock(mat))return 1;
        return 0;
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends