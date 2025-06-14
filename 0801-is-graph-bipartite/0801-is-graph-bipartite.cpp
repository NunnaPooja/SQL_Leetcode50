class Solution {
public:
    bool dfs(int node,int color,vector<int>& colors,vector<int>&visited,vector<vector<int>>& graph){
        visited[node]=1;
        colors[node]=color;
        for(auto it:graph[node]){
            if(visited[it]!=1){
                if(dfs(it,!color,colors,visited,graph)==false) return false; //return statement was not written before hence 
                //gave wrong answer
            } 
            else if(colors[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //if we are able to color with alterante colors then we can call that fraph as bipartite
        int n=graph.size();
        vector<int>colors(n,0);
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                if(dfs(i,0,colors,visited,graph)==false) return false;
            } 
        }
        return true;
    }
};