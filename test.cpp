class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        if(n==0)
            return 0;
        
        vector<vector<int>> p(m,vector<int> (n,0));
        
        p[0][0]=grid[0][0];
        
        for(int i=1;i<m;i++)
            p[i][0]=p[i-1][0]+grid[i][0];
        
        for(int j=1;j<n;j++)
            p[0][j]=p[0][j-1]+grid[0][j];
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                int t1=p[i-1][j]+grid[i][j];
                int t2=p[i][j-1]+grid[i][j];
                p[i][j]=min(t1,t2);
            }
        }
        
        return p[m-1][n-1];
    }
};
