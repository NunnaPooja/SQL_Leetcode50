class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        q=[]
        r=len(grid)
        c=len(grid[0])
        cnt=0
        delr=[-1,0,1,0]
        delc=[0,-1,0,1]
        vis=[[0]*c for _ in range(r)]
        for i in range(0,r):
            for j in range(0,c):
                if not vis[i][j] and grid[i][j]=="1":
                    cnt+=1
                    q.append((i,j))
                    while q:
                        row,col=q.pop()
                        vis[row][col]=1
                        for k in range(0,4):
                            newr=row+delr[k]
                            newc=col+delc[k]
                            if (0<=newr<r) and (0<=newc<c) and vis[newr][newc]==0 and grid[newr][newc]=="1":
                                q.append((newr,newc))

        return cnt


