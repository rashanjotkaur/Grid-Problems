// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0/?track=md-graph&batchId=144
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
vector <int> row{0,0,-1,1};
vector <int> col{-1,1,0,0};

int find_dis(vector <vector<int>> grid,int n,int m,int dr,int dc){
// 	vector <vector<bool>> vis(n,vector<bool> (m,false));
	vector <vector<int>> path(n,vector <int> (m,INT_MAX));
	priority_queue <ppi,vector <ppi>,greater<ppi>> pq;
	pq.push(make_pair(0,make_pair(0,0)));
	path[0][0]=0;
	while(!pq.empty()){
	    int w = pq.top().first;
        int rr = pq.top().second.first;
        int cc = pq.top().second.second;
        pq.pop();
        
        if(rr==dr && cc==dc)
            return w;
        for(int k=0 ; k<4 ; k++){
            int r = rr + row[k];
            int c = cc + col[k];
            
            if(r<0||r>=n) continue;
            if(c<0||c>=m) continue;
            if(grid[r][c]==0) continue;
            
            
            int dis = w + 1;
            if(dis<path[r][c]){
                path[r][c] = dis;
                pq.push(make_pair(dis,make_pair(r,c)));
            }
        }
    }
    return -1;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,x;
    	cin>>n>>m;
    	vector <vector<int>> grid(n,vector <int> (m));
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			cin>>x;
    			grid[i][j]=x;
    		}
    	}
    	int dr,dc;
    	cin>>dr>>dc;
    	if(grid[0][0]==1){
        	cout<<find_dis(grid,n,m,dr,dc)<<endl;
    	}
    	else 
    	    cout<<"-1"<<endl;
	}
	return 0;
}

