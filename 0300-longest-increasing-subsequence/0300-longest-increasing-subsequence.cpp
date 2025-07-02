class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      //tabulation
      int n=nums.size();
      vector<int>dp(n+1,1); 
      int maxi=0;
      for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i]) dp[i]=max(dp[prev]+1,dp[i]);
        }
        maxi=max(maxi,dp[i]);
      } 
      return maxi;
    }
};