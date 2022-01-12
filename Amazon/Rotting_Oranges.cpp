class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        int m=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        bool flag =false;
        bool flag2=true;
        while(!flag)
        {
            flag =true;
            vector<vector<int>> mat=grid;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    
                    if(grid[i][j]==2)
                    {
                        grid[i][j]=-1;
                        for(int k=0;k<4;k++)
                         {
                            int di=i+dx[k];
                            int dj=j+dy[k];
                            if(di>=0&&di<n&&dj>=0&&dj<m)
                            {
                                if(grid[di][dj]==1)
                                {
                                    mat[di][dj]=2;
                                    if(flag)cnt++;
                                    flag=false;
                                    flag2=false;
                                    
                                }
                           
                            }
                            
                         }
                        //if(!flag)break;
                    }
                   
                }
            }
            grid=mat;
        }
       // if(flag2)return -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
                }
        }
        return cnt;
        
    }
};