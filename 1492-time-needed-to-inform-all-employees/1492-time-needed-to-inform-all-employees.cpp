class Solution {
public:
int maxi=0;
vector<int>vis;
void dfs(int node,int par,int time,vector<vector<int>> &edge, vector<int>&informTime){
    vis[node]=1;
    if(par==-1) time=0;
    else time=time+informTime[par];
    maxi=max(maxi,time);
for(auto it:edge[node]){
    if(vis[it]!=1){
dfs(it,node,time,edge,informTime);
    }
}
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edge(n);
        for(int i=0;i<manager.size();i++){
            int u=i;
            int v=manager[i];
            if(v==-1) continue;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        vis.resize(n,0);
        dfs(headID,-1,0,edge,informTime);
        return maxi;
    }
};