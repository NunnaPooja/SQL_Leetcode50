class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0) return -1;
        vector<int>prefixsum(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=stones[i];
            prefixsum[i+1]=cnt;
            // cout<<prefixsum[i+1];
        }
        //else dp table
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int m=0;m<n;m++){
            int i=0;
            int j=m;
            int len=j-i+1;
            if(len<k) continue;
            while(j<=n-1){
                if(len==k) dp[i][j]=prefixsum[j+1]-prefixsum[i];
                else{
                    //partition point
                    dp[i][j]=INT_MAX/4;
                    for(int p=i;p<j;p++){
                        if((j-p-1)%(k-1)==0 || (p-i)%(k-1)==0) dp[i][j]=min(dp[i][j],dp[i][p]+dp[p+1][j]);
                    }
                    if((len-1)%(k-1)==0) dp[i][j]+=prefixsum[j+1]-prefixsum[i];
                }
                cout<<dp[i][j]<<" ";
                i++;
                j++;
            }
            
        }
        return dp[0][n-1];
    }
};