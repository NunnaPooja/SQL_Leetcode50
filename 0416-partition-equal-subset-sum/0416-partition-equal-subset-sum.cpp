class Solution {
public:
bool f(int sum,int ind,vector<int>& nums,vector<vector<int>>&dp){
    int n=nums.size();
    if(sum==0) return true;
    if(ind==n &&sum!=0) return false;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    bool not_pick=f(sum,ind+1,nums,dp);
    bool pick=false;
    if(nums[ind]<=sum) pick=f(sum-nums[ind],ind+1,nums,dp); //<= has to be the condition, misatake before was >=
    return dp[ind][sum]=pick||not_pick; //stores as 1 or 0 in dp
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(auto num:nums){
            total+=num;
        }
        if(total%2!=0) return false; //odd total sum, no possible to split into 2 subsets.
        int target=total/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(target,0,nums,dp);
    }
};