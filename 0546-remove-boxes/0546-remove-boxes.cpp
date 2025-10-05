int dp[101][101][101];
class Solution {
public:
int f(int l,int r, int k,vector<int>&boxes){
    if(l>r) return 0;
    int k_here=k;
    int l_here=l;
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    while(l+1<=r && boxes[l]==boxes[l+1]){
        l++;
        k++;
    }
    int ans=(k+1)*(k+1)+f(l+1,r,0,boxes);
    for(int m=l+1;m<=r;m++){
        if(boxes[l]==boxes[m]){
            ans=max(ans,f(m,r,k+1,boxes)+f(l+1,m-1,0,boxes));
        }
    }
    return dp[l_here][r][k_here]=ans;
}
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,-1,sizeof(dp));
       return f(0,n-1,0,boxes); 
    }
};