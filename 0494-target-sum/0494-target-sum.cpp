class Solution {
public:
int f(int sum,int ind,vector<int>& nums, int target){
    int n=nums.size();
    if(ind==n-1 && sum==target) return 1;
    else if(ind==n-1) return 0;
    return f(sum+nums[ind+1],ind+1,nums,target)+f(sum-nums[ind+1],ind+1,nums,target);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums[0],0,nums,target)+f(-nums[0],0,nums,target);
    }
};