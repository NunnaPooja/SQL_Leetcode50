int dp[9][1<<18];
class Solution {
public:
int f(int op,int mask,vector<int>& nums){
    //base case
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))) cnt++;
    }
    if(cnt==n) return 0;
    if(dp[op][mask]!=-1) return dp[op][mask];
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        // if((mask &(1<<i))) continue;
        for(int j=i+1;j<n;j++){
            // if((mask &(1<<j))) continue;
            if(i!=j && (mask&(1<<i))==0 && (mask&(1<<j))==0 ){ //not used before
                int temp=f(op+1,mask|(1<<i)|(1<<j),nums);
                if(temp!=INT_MAX){
                    ans=max(ans,op*(__gcd(nums[i],nums[j]))+temp); //return max value
                }
            }
        }
    }
    return dp[op][mask]=ans;
}
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return f(1,0,nums); 
    }
};