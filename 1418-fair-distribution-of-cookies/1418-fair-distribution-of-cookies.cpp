// int dp[9][1<<9];
class Solution {
public:
void f(int ind,int mask,vector<int>&child,vector<int>&cookies,int &ans){
    int n=cookies.size();
    if(ind==n){
        ans=min(ans,*max_element(child.begin(),child.end()));
        return;
    }
    int k=child.size();
    for(int i=0;i<k;i++){ //allot present index element to all childrens
        if((mask&(1<<ind))==0){ //unused before
            child[i]+=cookies[ind];
            f(ind+1,mask|(1<<ind),child,cookies,ans);
            child[i]-=cookies[ind];
        }
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        int ans=INT_MAX;
        // memset(dp,-1,sizeof(dp));
        f(0,0,child,cookies,ans); //ind,mask,child,array
        return ans;
    }
};