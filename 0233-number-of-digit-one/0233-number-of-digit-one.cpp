int dp[11][2][10];
class Solution {
public:
int f(string &s,int indx,int tight,int cnt_of_1){
    int n=s.size();
    if(indx==n) return cnt_of_1;
    if(dp[indx][tight][cnt_of_1]!=-1) return dp[indx][tight][cnt_of_1];
    int ans=0;
    int lb=0;
    int ub=(tight==1)? s[indx]-'0':9;
    for(int dig=lb;dig<=ub;dig++){
        ans+=f(s,indx+1,tight &&(dig==s[indx]-'0'),cnt_of_1+(dig==1));
    }
    return dp[indx][tight][cnt_of_1]=ans;
}
    int countDigitOne(int n) {
        //index,tight,countof1s
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return f(s,0,1,0);
    }
};