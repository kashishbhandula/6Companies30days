class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int>Sum(n,0);
        Sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            Sum[i]+=nums[i];
            Sum[i]+=Sum[i-1];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int val=target;
            if(i>0)
            {val+=Sum[i-1];}
            int pos=lower_bound(Sum.begin(),Sum.end(),val)-Sum.begin();
            if(pos!=n)
            {
                ans=min(ans,pos-i+1);
            }
            
            
        }
        if(ans==INT_MAX)
        {
            //cout<<0<<endl;
            return 0;
        }
        //cout<<ans<<endl;
        return ans;
        
        
    }
};