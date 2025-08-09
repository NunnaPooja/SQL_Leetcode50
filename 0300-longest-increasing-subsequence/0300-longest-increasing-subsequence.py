class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        ans=[]
        ans.append(nums[0])
        for num in nums:
            if num>ans[-1]:
                ans.append(num)
            else:
                ans[bisect_left(ans,num)]=num #replace lowerbound element with the current element
        
        return len(ans)
        