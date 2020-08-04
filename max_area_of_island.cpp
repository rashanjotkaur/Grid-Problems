//https://leetcode.com/problems/max-area-of-island/

void dfs(vector <vector<int>> &grid,int i,int j,int row,int col,int &count){
        if(i>=row || i<0 || j>=col || j<0)
            return ;
        
        if(grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        count++;
        dfs(grid,i-1,j,row,col,count);
        dfs(grid,i+1,j,row,col,count);
        dfs(grid,i,j-1,row,col,count);
        dfs(grid,i,j+1,row,col,count);        
    }
    int maxAreaOfIsland(vector <vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                if(grid[i][j]==1)
                    dfs(grid,i,j,n,m,count);
                maxi=max(count,maxi);
            }
        }
        return maxi;
    }
