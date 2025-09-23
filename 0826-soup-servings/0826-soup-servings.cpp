class Solution {
public:
double f(int a,int b,vector<pair<int,int>>&ml,vector<vector<double>>&dp){
    if(a<=0 &&b<=0) return 0.5;
    if(a<=0) return 1;
    if(b<=0) return 0;
    if(dp[max(0,a)][max(0,b)]!=-1.0) return dp[max(0,a)][max(0,b)]; //max(0,a) and max(0,b) as a and b could go as negative
    double ans=0;
    for(int k=0;k<4;k++){
        ans+=0.25*f(a-ml[k].first,b-ml[k].second,ml,dp);
    }
    return dp[max(0,a)][max(0,b)]=ans;
}
    double soupServings(int n) {
        if(n>5000) return 1; //as for n>5000, probability is almost 1
        vector<pair<int,int>>ml;
        int i=100,j=0;
        ml.push_back({100,0});
        for(int k=1;k<4;k++){
            int ni=ml.back().first-25;
            int nj=ml.back().second+25;
            ml.push_back({ni,nj});
        }
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return f(n,n,ml,dp);
    }
};