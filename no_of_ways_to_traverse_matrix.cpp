#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int count_paths(vector <vector<int>> &dp,int n,int m){
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j]!=-1){
        
                if(dp[i][j-1]!=-1)
                    dp[i][j]=(dp[i][j]%mod+dp[i][j-1]%mod)%mod;
                        
                if(dp[i-1][j]!=-1)
                    dp[i][j]=(dp[i][j]%mod+dp[i-1][j]%mod)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m;
        vector <vector<int>> dp(n,vector <int> (m,0));
        dp[0][0]=1;
        cin>>k;
        int x,y;
        for(int i=0;i<k;i++){
            cin>>x>>y;
            x--;
            y--;
            dp[x][y]=-1;
        }
        for(int j=1;j<m;j++){
            if(dp[0][j]==-1)
                break;
            dp[0][j]=1;
        }
        for(int i=1;i<n;i++){
            if(dp[i][0]==-1)
                break;
            dp[i][0]=1;
        }
        if(dp[0][0]==-1)
            cout<<"0"<<endl;
        else
            cout<<count_paths(dp,n,m)<<endl;
    }
	return 0;
 }
