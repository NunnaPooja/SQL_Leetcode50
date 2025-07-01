class Solution {
public:
    int fib(int n) {
       //basecase
       if(n==0) return 0;
       if(n==1) return 1;
       vector<int>dp(n+1); //here if n==0 it creates dp of size 1 then dp[1] will be initialised causing run time error
       dp[0]=0;
       dp[1]=1;
       //recursion
       for(int i=2;i<=n;i++){ //u can run loop from 2
        dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
    }
};