class Solution {
public:
vector<int>delr={-1,0,1,0};
vector<int>delc={0,-1,0,1};
bool f(int r, int c,vector<vector<char>>& board,string word,int ind,vector<vector<int>>&vis ){
    if(ind==word.size()-1) return true;
    int m=board.size();
    int n=board[0].size();
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int newr=r+delr[i];
        int newc=c+delc[i];
        if(newr>=0 && newr<m && newc>=0 && newc<n && vis[newr][newc]!=1){
            if(board[newr][newc]==word[ind+1]){
                if(f(newr,newc,board,word,ind+1,vis)) return true;
    }
    // else{
    //     if(f(newr,newc,board,word,ind,vis)) return true;
    // }
        }
    }
    vis[r][c]=0;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int sn=word.size();
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        if(board[i][j]==word[0]){ //start with start letter
             if(f(i,j,board,word,0,vis)) return true;
        }
            }
        }
        return false;
    }
};