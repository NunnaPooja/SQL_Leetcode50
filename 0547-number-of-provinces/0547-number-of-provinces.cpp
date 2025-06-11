class Solution {
public:
 void dfs(int node,vector<vector<int>> &adj,vector<int> &visited){
    // if(visited[node]==1) return; =>you can remove this if u put a check inside for loop below
    visited[node]=1;
    for(auto it: adj[node]){
        if(visited[it]==0) dfs(it,adj,visited); //call funcn only if the node is unvisited
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //making  into list
        int n= isConnected.size();
        vector<int>visited(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){ // i!=j to avoid self edges
                   adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                cnt++;
                dfs(i,adj,visited); //call dfs only if the node is unvisited
            }
        }
        return cnt;
    }
};