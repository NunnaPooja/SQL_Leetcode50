class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        arr=[]
        # prev1=intervals[0][0]
        # prev2=intervals[0][1]
        # arr.append([prev1,prev2])
        # for i in range(1,len(intervals)):
        #     u,v=intervals[i]
        #     back=arr[-1][1]
        #     if u<=back:
        #         back=max(back,v)
        #         arr[-1][1]=back
        #     elif newInterval[0]<=back:
        #         back=max(back,newInterval[1])
        #         arr[-1][1]=back
        #     elif newInterval[0]>back and newInterval[0]<u:
        #         arr.append(newInterval)
        #         while i<n:
        #             arr.append(intervals[i])
        #             i+=1
        #         break
        #     elif u>back:
        #         arr.append([u,v])
        n=len(intervals)
        i=0
        #add non merging intervals
        while i<n and intervals[i][1]<newInterval[0]:
            arr.append(intervals[i])
            i+=1
        #merge 
        while i<n and not(intervals[i][0]>newInterval[1]) and not(intervals[i][1]<newInterval[0]):
            newInterval[0]=min(intervals[i][0],newInterval[0])
            newInterval[1]=max(intervals[i][1],newInterval[1])
            i+=1
        arr.append(newInterval)
        #add rem elements
        while i<n:
            arr.append(intervals[i])
            i+=1

        return arr
