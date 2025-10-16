class Solution {
public:
vector<int>vis;
vector<int>color;
bool dfs(int node,vector<vector<int>>&adj,int clr){
    vis[node]=1;
    color[node]=clr;
    for(auto neigh:adj[node]){
        if(!vis[neigh]){
            if(dfs(neigh,adj,!clr)==false) 
                return false;
        }
        else{
            if(color[neigh]==clr) return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n+1);
        color.resize(n+1,-1);
        for(int i=1;i<=n;i++){
            if(!vis[i]) 
                if(dfs(i,adj,1)==false) return false;
        }
        return true;
    }
};