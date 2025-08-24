from functools import cmp_to_key
class Solution:
    def compare(self,a,b):
        return a[0]-b[0]
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # if len(intervals)==0:
        #     return [] no  need of this condition as it was mentioned that intervals size is minimum of 1
        arr=[]
        intervals.sort(key=cmp_to_key(self.compare))
        prev1=intervals[0][0]
        prev2=intervals[0][1]
        arr.append([prev1,prev2])
        for i in range(1,len(intervals)):
            u,v=intervals[i]
            if u<=arr[-1][1]:
                arr[-1][1]=max(arr[-1][1],v)
            else:
                arr.append([u,v])
            
        return arr


        