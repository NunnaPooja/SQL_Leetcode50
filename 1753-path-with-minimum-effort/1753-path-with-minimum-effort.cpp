class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
       queue<pair<int,pair<int,int>>>q;
       q.push({0,{0,0}}); //difference, row,col
       vector<vector<int>>minidiff(r,vector<int>(c,INT_MAX)); //to store minimum value of max of difference of path till i,j indices
       minidiff[0][0]=0;
       while(!q.empty()){
        int difference=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        vector<int>delrow={1,0,-1,0};
        vector<int>delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<r && ncol>=0 &&ncol<c){
                int newdiff=max(abs(heights[nrow][ncol]-heights[row][col]),difference); //consider maxdifference in that path
                if(newdiff<minidiff[nrow][ncol]){
                minidiff[nrow][ncol]=newdiff; //update the minidiff matrix if u found minimum difference in certain path
             q.push({newdiff,{nrow,ncol}});
                }
            }
        }
       }
       return minidiff[r-1][c-1];
    }
};