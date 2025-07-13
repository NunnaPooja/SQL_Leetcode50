class Solution {
public:
// int f(int ind,int steps, vector<vector<int>>&dp, vector<int>& nums){
//     int n=nums.size();
//     if(ind>=n-1) return steps;
//     if(dp[ind][steps]!=-1) return dp[ind][steps];
//     int mini=INT_MAX;
//     for(int i=1;i<=nums[ind];i++){
//         int newind=ind+i;
//         int stepsinc=steps+1;
//         mini=min(mini,f(newind,stepsinc,dp,nums));
//     }
//     return dp[ind][steps]=mini;
// }
    int jump(vector<int>& nums) {
        //greeady approach O(N)
       int n=nums.size();
       if(n==1) return 0;
       int lind=0; //left index //at minimum range value
       int rind=0; //right index //stays at maximim range
       int steps=0; //inital steps
       while(rind<n-1){
        int farthest=0;
        //u need to check for all the possible ranges from lind to rind
        for(int ind=lind;ind<=rind;ind++){
            farthest=max(farthest,ind+nums[ind]);
        }
        lind=rind+1;
        rind=farthest;
        steps++;
       }
       return steps;
    }
};