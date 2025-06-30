class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //if we are able to color with alterante colors then we can call that fraph as bipartite
        //BFS soln
        int n=graph.size();
        vector<int>colors(n,-1); //assigning color as -1 representing non colored node
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){ //need to check for disconnected components as well
        /*For example, consider a graph with two disconnected bipartite subgraphs:
        Component 1: 
        1↔2
        Component 2: 
        3↔4
        Both components can still belong to the same two teams: {1, 3} and {2, 4}.
        */
            if(colors[i]==-1){ //call dfs for non colored node
                q.push({i,0});
                colors[i]=0;
                while(!q.empty()){
                    auto [node,clr]=q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(colors[it]==-1){
                            q.push({it,!clr});
                        colors[it]=!clr;
                        }
                        else{
                            if(colors[it]==clr) return false;
                        }
                    }
                }
            } 
        }
        return true;
    }
};