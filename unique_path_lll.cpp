// https://leetcode.com/problems/unique-paths-iii/submissions/
int m;
    int n;
    int startx;
    int starty;
    int endx;
    int endy;
    int ans=0;
    int paths;
    void dfs(vector<vector<int>> grid, int x, int y, int path){
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==-1)
            return;
        if(x==endx && y==endy && path==paths){
            ans++;
            return;
        }
        grid[x][y]=-1;
        dfs(grid,x,y+1,path+1);
        dfs(grid,x+1,y,path+1);
        dfs(grid,x,y-1,path+1);
        dfs(grid,x-1,y,path+1);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        paths=m*n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                else if(grid[i][j]==2){
                    endx=i;
                    endy=j;
                }
                else if(grid[i][j]==-1)
                    paths--;
            }
        }
        dfs(grid,startx,starty,1);
        return ans;
    }
    
