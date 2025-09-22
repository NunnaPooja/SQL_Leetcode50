const int mod=1e9+7;
class Solution {
public:
//recursive solution
int f(int ind, string s){
    int n=s.size();
    if(ind==s.size()) return 1;
    int ans=0;
    ans+=f(ind+1,s);
    if(ind+2<n && s[ind+1]==s[ind] &&s[ind]==s[ind+2]){
        ans+=f(ind+3,s);
    }
    if(ind+1<n && s[ind]==s[ind+1]){
        ans+=f(ind+2,s);
    }
    return ans%mod;
}
    int countTexts(string pressedKeys) {
        int n=pressedKeys.size();
        vector<int>dp(n+1,0); //tabulation
        // return f(0,pressedKeys);
        dp[0]=1;
        // dp[1]=1;
        // dp[2]=2; it is not always 2, if string is 22 dp[2]=2 but if it is 23 then dp[2]=1
        // dp[3]=4;
        // for(int i=4;i<=n;i++){
            for(int i=1;i<=n;i++){
            int ans=0;
            ans=(ans+dp[i-1])%mod;
            //before forgot abt 4 chars matching i
            //for 4 chars //check for only digits 7 and 9, as they only has 4 words in it
           if(i-4>=0 && (pressedKeys[i-1]=='7' ||pressedKeys[i-1]=='9') && pressedKeys[i-1]==pressedKeys[i-4]  &&pressedKeys[i-2]==pressedKeys[i-1] &&pressedKeys[i-1]==pressedKeys[i-3]){
        ans=(ans+dp[i-4])%mod;;
           }
            //3 chars
           if(i-3>=0 && pressedKeys[i-2]==pressedKeys[i-1] &&pressedKeys[i-1]==pressedKeys[i-3]){
        ans=(ans+dp[i-3])%mod;
    } 
    //2 chars
    if(i-2>=0 && pressedKeys[i-1]==pressedKeys[i-2]){
        ans=(ans+dp[i-2])%mod;
    }
    dp[i]=ans;
        }
        return dp[n]%mod;
    }
};