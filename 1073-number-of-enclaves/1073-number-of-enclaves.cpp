class Solution {
public:
void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
vector<int>row={1,0,-1,0};
    vector<int>col={0,1,0,-1};
    int m=grid.size();
      int n=grid[0].size();
    visited[r][c]=1;
    for(int k=0;k<4;k++){
            int newr=r+row[k];
            int newc=c+col[k];
            if(newr>=0&&newr<m && newc>=0 && newc<n && grid[newr][newc]==1 &&visited[newr][newc]!=1) dfs(newr,newc,grid,visited);
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        //perform dfs to edge elements(marking visited matrix)
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(grid[i][j]==1 &&visited[i][j]!=1) dfs(i,j,grid,visited); 
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1 &&visited[i][j]!=1) cnt++;
        }
        }
        return cnt;
    }
};