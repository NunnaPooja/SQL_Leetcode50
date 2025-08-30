class Solution:
    def f(self,nums,i,total,target,dp,os):
        if total==target and i==len(nums):
            return 1
        elif i==len(nums):
            return 0
        if dp[i][total+os]!=-1 : #before mistakenly left as dp[i][total]!=-1, hence corrected with if dp[i][total+os]!=-1
            return dp[i][total+os]
        take=self.f(nums,i+1,total-nums[i],target,dp,os)
        not_take=self.f(nums,i+1,total+nums[i],target,dp,os)
        ans=take+not_take
        dp[i][total+os]=ans
        return dp[i][total+os]

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        rows=len(nums)
        cols=2*sum(nums)+1
        #min value= min_val+offset= -sum(nums)+offset= -sum(nums)+sum(nums)=0
        #max value of dp=max_val+offset= sum(nums)+offset= sum(nums)+sum(nums)=2*sum(nums)
        # hence cols=2*sum(nums) in dp table
        dp=[[-1]*(cols+1) for _ in range(rows+1)] #store all possible sums
        # for i in range(rows,0):
        #     for j in range(target+1,0):
        offset=sum(nums)
        return self.f(nums,0,0,target,dp,offset)

            
        