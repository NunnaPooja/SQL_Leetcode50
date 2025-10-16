class Solution {
public:
bool dpfun(string s, unordered_set<string>&st){
    int n=s.size();
    if(s.empty()) return false;
    // for(int i=0;i<=n-1;i++){
    //     int i=0;
    //     int j=k;
    //     while(j<=n-1){
    //         if(st.count(s.substr(i,j-i+1))>0) dp[i][j]=0;
    //         else{
    //             dp[i][j]=INT_MAX;
    //             for(int k=i;k<j;k++){
    //                 dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
    //             }
    //         }
    //         i++;
    //         j++;
    //     }
    // }
    // return dp[0][n-1];
    vector<bool>dp(n+1,false);
    dp[0]= true; //empty string
    // for(int i=0;i<n;i++){
        // for(auto it:st){
        //     int m=it.size();
        //     if(m>n-i) continue;
        //     if((s.substr(i,m)==it) && (i-1==-1 || dp[i-1]==true)){
        //         dp[i+m-1]=true;
        //     }
        // }
        //}
        //above loop t.c=O(N*W*M) W=size of st, M=len of substring
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){ //sliding window approach to check if present or not
        if(!dp[j]) continue;
            if(st.count(s.substr(j,i-j)))
                dp[i]=true;
                // break; //have to break;
        }
    }
    return dp[n];
}
static bool comp(string a, string b){
    return a.size()<b.size();
}
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st;
        sort(words.begin(),words.end(),comp);
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            if(dpfun(s,st)) ans.push_back(s);
            st.insert(s);
                }
                return ans;
    }
};