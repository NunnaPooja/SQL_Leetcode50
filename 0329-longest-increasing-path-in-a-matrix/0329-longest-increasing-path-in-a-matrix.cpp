class Solution {
public:
int maxi=1;
vector<int>delr={-1,0,1,0};
vector<int>delc={0,1,0,-1};
vector<vector<int>>dp;
int dfs(int r,int c,vector<vector<int>>&matrix){
    // vis[r][c]=1;
    if(dp[r][c]!=-1) return dp[r][c];
    int m=matrix.size();
    int n=matrix[0].size();
    int best=1;
    for(int i=0;i<4;i++){
        int newr=r+delr[i];
        int newc=c+delc[i];
        if(newr>=0 && newr<m && newc>=0 && newc<n && (matrix[r][c]<matrix[newr][newc])){
                best=max(best,1+dfs(newr,newc,matrix));
            }
            // else{
            //     dfs(newr,newc,vis,len,matrix);
            // }
        }
    return dp[r][c]=best;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // vector<vector<int>>vis(m,vector<int>(n,0)); //no need of visited matrix
        dp.assign(m,vector<int>(n,-1)); //dp[r][c] denotes max increasing length from index r,c => repeated function calls,hence dp usage.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,dfs(i,j,matrix));
            }
        }
        return maxi;
    }
};