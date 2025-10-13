class Solution {
public:
    int numTrees(int n) {
        //left<node<right
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){ //computing for all dp indices till n size slowly by increasing size
            int sum=0;
            for(int root=1;root<=i;root++){ //summing up for each num as root node
            int left=dp[root-1]; //precomputed
            int right=dp[i-root]; //precomputed
            sum+=left*right;
            }
            dp[i]=sum;
        }
        return dp[n];
    }
};