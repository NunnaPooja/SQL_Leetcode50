class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)
        i=n-1
        ans=[0]*n
        stack=[]
        i=n-1
        map={}
        j=0
        #store indices in stack rather than numbers
        for num in reversed(temperatures):
            if len(stack)==0:
                ans[i]=0
            elif len(stack)!=0 and num<temperatures[stack[-1]]:
                ans[i]=1
            elif len(stack)!=0 and num>=temperatures[stack[-1]]:
                cnt=0
                while len(stack)!=0 and num>=temperatures[stack[-1]]:
                    cnt+=ans[stack[-1]]
                    stack.pop()
                if len(stack)!=0:
                    cnt+=1
                    ans[i]=cnt
                else:
                    ans[i]=0
            stack.append(i)
            i=i-1
        
        return ans




