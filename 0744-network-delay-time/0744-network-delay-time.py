import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj=[[] for _ in range(n+1)]
        # for num in times:
        #     adj[num[0]].append((num[1],num[2]))
        for u,v,w in times: #simpler syntax
            adj[u].append((v,w))
        heap=[]
        heapq.heappush(heap,(0,k))
        distcost=[float('inf')]*(n+1)
        distcost[k]=0 #imp 
        while heap:
            cost,node=heapq.heappop(heap) #pop and returns top element
            for neigh,cs in adj[node]:
                if distcost[neigh]>cost+cs:
                    distcost[neigh]=cost+cs
                    heapq.heappush(heap,(cost+cs,neigh))
                
        ans=max(distcost[1:]) #ma of indices elements from 1 to n-1
        if ans==float('inf'):
            return -1
        return ans




        
        