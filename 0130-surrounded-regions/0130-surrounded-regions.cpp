class Solution {
public:
void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>& visited){
    vector<int>row={1,0,-1,0};
    vector<int>col={0,1,0,-1};
    int m=board.size();
      int n=board[0].size();
    visited[r][c]=1;
    for(int k=0;k<4;k++){
            int newr=r+row[k];
            int newc=c+col[k];
            if(newr>=0&&newr<m && newc>=0 && newc<n && board[newr][newc]=='O' &&visited[newr][newc]!=1) dfs(newr,newc,board,visited);
    }
}
    void solve(vector<vector<char>>& board) {
      int m=board.size();
      int n=board[0].size();
      vector<vector<int>> visited(m,vector<int>(n,0));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==m-1 ||j==0||j==n-1){
                if(visited[i][j]!=1 &&board[i][j]=='O') dfs(i,j,board,visited);
            }  //perform dfs to edge elements to connect them coz whatever that's connected to edge element cannot be replaced by X
            //so basically u need to find the connected path of the edged Os and then except them replace other Os by X
            //how to u know they are connected? by visited matrix, u will mark those as 1
        }
      }
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O' &&visited[i][j]!=1) board[i][j]='X'; //before mistake was u declared board[i][j]=='X'
        }
      } 
    }
};