int dp[9][2][1<<10]; //index=[0,8],lz=bool=(0,1) ,mask of 10 digits 
class Solution {
public:
int f(int ind,int lz,int mask){
    if(ind<0) return 1;
    if(dp[ind][lz][mask]!=-1) return dp[ind][lz][mask];
    int ans=0;
    for(int i=0;i<=9;i++){
        if(i==0 && lz==1){
            ans+=f(ind-1,1,mask); //still leading zeroes
        }
        else if((mask &(1<<i))==0){ //digit unused
        ans+=f(ind-1,0, mask|(1<<i)); //no leading zeroes anymore
        }
    }
    return dp[ind][lz][mask]=ans;
}
    int countNumbersWithUniqueDigits(int n) {
        //return n.of digits whose adj digits are not same
        //ind,tight,prev,lz(leading zeroes)
        memset(dp,-1,sizeof(dp));
        return f(n-1,1,0); //tight and lz are bool type, let us initialise prev as something that is not possible as -1 causes index issue in dp, taking as 10
    }
};