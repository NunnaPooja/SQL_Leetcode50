class Solution {
public:
    bool dfs(int node,int color,vector<int>& colors,vector<vector<int>>& graph){
        colors[node]=color;
        for(auto it:graph[node]){
            if(colors[it]==-1){
                if(dfs(it,!color,colors,graph)==false) return false; //return statement was not written before hence 
                //gave wrong answer
            } 
            else if(colors[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //if we are able to color with alterante colors then we can call that fraph as bipartite
        int n=graph.size();
        vector<int>colors(n,-1); //assigning color as -1 representing non colored node
        for(int i=0;i<n;i++){
            if(colors[i]==-1){ //call dfs for non colored node
                if(dfs(i,0,colors,graph)==false) return false;
            } 
        }
        return true;
    }
};