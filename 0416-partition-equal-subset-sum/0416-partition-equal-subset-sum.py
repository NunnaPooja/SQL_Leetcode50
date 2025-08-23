class Solution:
    def summation(self,ind,target,nums,dp):
        if target==0:
            return True
        elif ind>=len(nums):
            return False
        if dp[ind][target]!=None:
            return dp[ind][target]
        take=False
        if nums[ind]<=target:
            take=self.summation(ind+1,target-nums[ind],nums,dp)
        not_take=self.summation(ind+1,target,nums,dp)
        dp[ind][target]= take or not_take
        return dp[ind][target]
    def canPartition(self, nums: List[int]) -> bool:
        sum=0
        for num in nums:
            sum+=num
        if sum%2!=0:
            return False
        else:
            sum=sum//2
        n=len(nums)
        #for sum=10 we need table for indices from 0 to 10 , rather than 0 to 9, hence (sum+1)
        dp=[[None]*(sum+1) for _ in range(n)]
        return self.summation(0,sum,nums,dp)

