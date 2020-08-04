// https://leetcode.com/problems/unique-paths-ii/
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        
        vector <vector<int>> dp(n,vector <int> (m,0));
        dp[0][0]=1;
        int i,j;
        for(i=1;i<n;i++){
            if(grid[i][0]==1)
                 break;
            dp[i][0]=1;
        }
        for(j=1;j<m;j++){
            if(grid[0][j]==1)
                break;
            dp[0][j]=1;
        }
        
        for(i=1;i<n;i++){
            for(j=1;j<m;j++)
                if(grid[i][j]==1)
                    dp[i][j]=-1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]!=-1){
                    if(dp[i-1][j]!=-1)
                        dp[i][j]=dp[i][j]+dp[i-1][j];
                    if(dp[i][j-1]!=-1)
                        dp[i][j]=dp[i][j]+dp[i][j-1];
                }
            }
        }
        if(dp[n-1][m-1]==-1)
            return 0;
        return dp[n-1][m-1];
    }
