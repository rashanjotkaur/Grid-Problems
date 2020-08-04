// https://leetcode.com/problems/number-of-islands/
void dfs(vector <vector<char>> &grid,int i,int j,int row,int col){
        if(i>=row || i<0 || j>=col || j<0)
            return ;
        
        if(grid[i][j]=='0')
            return;
        
        grid[i][j]='0'; //using this for marking visited
        
        dfs(grid,i-1,j,row,col);
        dfs(grid,i+1,j,row,col);
        dfs(grid,i,j-1,row,col);
        dfs(grid,i,j+1,row,col);        
    }
    int numIslands(vector <vector<char>> &grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count; 
    }
