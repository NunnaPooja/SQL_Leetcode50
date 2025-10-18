const int MOD=1e9+7;
class Solution {
public:
int dp[1001][1<<12];
/*Why dp states are col and prev states eventhough row and curr states are changing in recursive calls?
Within a given column, we fill all rows recursively.
The only information needed to compute the number of valid fillings for future columns is the pattern of the previous column.
row and curr are intermediate variables used only to build the pattern of the current column; they are not part of the global state once the column is done.
So we memoize only at the point where an entire column is finished — i.e. when row == 0 (the start of the next column fill).*/
int f(int col,int row,int curr,int prev,int m,int n){
    if(col==n) return 1;
    // vector<int>newcurr(m,0);
    if(row==m) return f(col+1,0,0,curr,m,n); //before curr vector becomes prev for next row
    if(row==0 && dp[col][prev]!=-1) return dp[col][prev]; 
    int ans=0;
    
    int up=(prev>>((m-row-1)*2))&3;
    int left=curr&3;
    for(int c=1;c<=3;c++){ //check for 3 colors 
        if(c!=left && c!=up) { //condition to assign new row
            ans=(ans+f(col,row+1,(curr<<2)|c,prev,m,n))%MOD;
    }  
    }
    if(row==0) dp[col][prev]=ans; //So we memoize only at the point where an entire column is finished
    // — i.e. when row == 0 (the start of the next column fill).
    return ans;
}
    int colorTheGrid(int m, int n) {
       //prev and current 
    //    vector<int>prev(m,0);
       //0->m-1 rows, 0->n-1 cols
    //    vector<int>curr(m,0);
       memset(dp,-1,sizeof(dp));
       return f(0,0,0,0,m,n); //col,row
    }
};