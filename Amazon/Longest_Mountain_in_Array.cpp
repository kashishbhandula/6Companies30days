class Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool flag=false;
        int n=arr.size();
        if(n<3)return 0;
        int ans=0;
        int start=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]==arr[i])
            {
                 start=INT_MAX;
                continue;
            }
            if(arr[i]>arr[i-1])
            {
                
                if(flag)
                {
                   
                    continue;
                }
                else
                {
                   start=i-1;
                    flag=true;
                }
            }
            else
            {
                
                    ans=max(ans,i-start+1);
                    flag=false;
                
                
               
                
                
            }
            
        }
        //if(!flag)ans=max(ans,n-start);
        return ans;
    }
};