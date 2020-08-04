// BFS
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
bool bfs(vector <vector<int>> mat,int n,int sr,int sc,int dr,int dc){
        vector <vector <bool>> vis(n,vector <bool> (n,false)); 
    	queue <pi> q;
    	
    	vector <int> row{-1,1,0,0};
        vector <int> col{0,0,-1,1};
    	
    	q.push(make_pair(sr,sc));
    	while(!q.empty()){
    	    int rr=q.front().first;
    	    int cc=q.front().second;
    	    q.pop();
    	    if(vis[rr][cc]) continue;
    	    vis[rr][cc]=true;
    	    for(int i=0;i<4;i++){
    	        int r=rr+row[i];
    	        int c=cc+col[i];
    	        if(r<0 || r>=n) continue;
    	        if(c<0 || c>=n)  continue;
    	        if(mat[r][c] && !vis[r][c]){
    	            q.push(make_pair(r,c));
    	        }
    	    }
    	}
    	return vis[dr][dc];
}
int main() {
	int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	vector <vector<int>> mat(n,vector <int> (n));
    	int sr,sc,dr,dc;
    	for(int i=0;i<n;i++){
    	    for(int j=0;j<n;j++){
    	        cin>>mat[i][j];
    	        if(mat[i][j]==1){
    	            sr=i;
    	            sc=j;
    	        }
    	        if(mat[i][j]==2){
    	            dr=i;
    	            dc=j;
    	        }
    	    }
	    }
    	cout<<bfs(mat,n,sr,sc,dr,dc)<<endl;
	}
    return 0;
}

//DFS
#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int> mat[],int row,int col,int N, vector<int> vis[]){
    if(row<0 || row>=N || col<0 || col>=N )
        return 0;
    if(vis[row][col]==1 || mat[row][col] == 0 )
        return 0;
        
    vis[row][col]=1;
    if(mat[row][col]==2)  // destination
        return 1;
    
    bool up=DFS(mat,row-1, col, N, vis);
    bool left=DFS(mat,row, col-1, N, vis);
    bool right=DFS(mat,row, col+1, N, vis);
    bool down=DFS(mat,row+1, col, N, vis);
    if(left || right || up || down)
        return 1;
}
int main(){
	int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector <int> mat[N];
        vector <int> vis[N];
        
        int sr,sc;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int x;
                cin>>x;
                mat[i].push_back(x);
                vis[i].push_back(0);
                if(x==1){
                    sr = i;
                    sc = j;
                }
            }
        }
        cout<<DFS(mat,sr,sc,N,vis)<<endl;
    }
    return 0;
}

// same as above DFS with small changes
#include<bits/stdc++.h>
using namespace std;
int DFS(vector<int> mat[],int row,int col,int dr,int dc,int N, 
    vector<int> vis[]){
        
    if(row<0 || row>=N || col<0 || col>=N )
        return 0;
    if(vis[row][col]==1 || mat[row][col]==0)
        return 0;
        
    vis[row][col]=1;
    if(row==dr && col==dc)  // destination
        return 1;
    
    bool up=DFS(mat,row-1, col, dr,dc,N, vis);
    bool left=DFS(mat,row, col-1,dr,dc,N, vis);
    bool right=DFS(mat,row, col+1,dr,dc,N, vis);
    bool down=DFS(mat,row+1, col,dr,dc,N, vis);
    if(left || right || up || down)
        return 1;
}
int main(){
	int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector <int> mat[N];
        vector <int> vis[N];
        
        int sr,sc,dr,dc;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int x;
                cin>>x;
                mat[i].push_back(x);
                vis[i].push_back(0);
                if(x==1){
                    sr = i;
                    sc = j;
                }
                else if(x==2){
                    dr = i;
                    dc = j;
                }
            }
        }
        if(dr<0 ||dr>=N || dc<0 || dc>=N)
            cout<<0<<endl;
        else 
            cout<<DFS(mat,sr,sc,dr,dc,N,vis)<<endl;
    }
    return 0;
}
