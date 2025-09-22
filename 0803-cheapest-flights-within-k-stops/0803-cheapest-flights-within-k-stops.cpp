class Solution {
public:
    int f(int src,int dst,vector<vector<pair<int,int>>>&adj,int k,vector<vector<int>>&dp){
        if(src==dst && k>=0) return 0;
        if(k<0) return INT_MAX; //to stop infinite recursion , this base case is necessary
        if(dp[src][k]!=-1) return dp[src][k];
        int price=INT_MAX;
        for(auto it:adj[src]){
                int temp=f(it.first,dst,adj,k-1,dp);
                if(temp!=INT_MAX)
                    price=min(price,it.second+temp);
            }
        return dp[src][k]=price;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+2,-1));
        vector<vector<pair<int,int>>>adjlist(n);
        for(int i=0;i<flights.size();i++){
            auto it=flights[i];
            adjlist[it[0]].push_back({it[1],it[2]});
        }
        int ans=f(src,dst,adjlist,k+1,dp); //k+1 is key here
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};