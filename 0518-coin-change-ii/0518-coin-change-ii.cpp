class Solution {
public:
int f(vector<int>& coins,vector<vector<int>>&dp,int i,int amount){
 //base case
 if(i==0){
    return (amount%coins[0]==0); //either returns 1(if true) or 0(if false)
 }
 if(dp[i][amount]!=-1) return dp[i][amount];
 //not take
 int ntk=f(coins,dp,i-1,amount); //move to before index
 int tk=0;
 if(coins[i]<=amount) tk=f(coins,dp,i,amount-coins[i]); //stay at the current index
 return dp[i][amount]=tk+ntk;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        //n-1 to 0 indexing and amount to 0 
        return f(coins,dp,n-1,amount); //arr,ind,target
    }
};