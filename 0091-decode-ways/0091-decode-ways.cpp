class Solution {
public:
int dp[102];
int f(int ind,string s){
    int n=s.size();
    if(ind==n) return 1;
    int ans=0;
    if(s[ind]=='0') return 0;
    if(dp[ind]!=-1) return dp[ind];
    ans+=f(ind+1,s);
    if(ind+1<n){
        // int num=(s[ind]-'0')*10+(s[ind+1]-'0');
        int  num=stoi(s.substr(ind,2));
        if(num>=10 && num<=26){
        ans+=f(ind+2,s);
        }
    }
    return dp[ind]=ans;
}
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s); //ind,string
    }
};