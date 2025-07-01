class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     //you can think of a priority queue but as the current value is dependent on current-1 and current-2 index so u can simply use dp
     int n=cost.size();
     vector<int>dp(n);
     dp[0]=cost[0];
     dp[1]=cost[1]; 
     for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
     }
     return min(dp[n-1],dp[n-2]); 
    }
};