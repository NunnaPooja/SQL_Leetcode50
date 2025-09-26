int dp[16][1<<15];
class Solution {
public:
int f(int time,int mask,vector<int>& tasks,int sessionTime){
    int n=tasks.size();
    if(__builtin_popcount(mask)==n) return 1;
    if(dp[time][mask]!=-1) return dp[time][mask];
    // else if()
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))) continue;
        if(tasks[i]<=time){
            ans=min(ans,f(time-tasks[i],mask|(1<<i),tasks,sessionTime)); 
        }
        else{ //start newsession
            ans=min(ans,1+f(sessionTime-tasks[i],mask|(1<<i),tasks,sessionTime));
        }
    }
    return dp[time][mask]=ans;
}
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp,-1,sizeof(dp));
        return f(sessionTime,0,tasks,sessionTime);
    }
};