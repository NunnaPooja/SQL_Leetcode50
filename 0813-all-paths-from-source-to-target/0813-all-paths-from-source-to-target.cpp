class Solution {
public:
vector<vector<int>> ans;
void dfs(int node,vector<int>temp,vector<int>vis,auto &graph){
    temp.push_back(node);
    vis[node]=1;
    if(node==graph.size()-1){
        ans.push_back(temp);
        return;
    }
    for(auto it:graph[node]){
        if(!vis[it]) dfs(it,temp,vis,graph);
    } 
    //as we need to find all possible ways, remove as visited so that other vertices might use them
    // temp.pop_back();
    // vis[node]=0;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        int n=graph.size();
        vector<int>vis(n,0);
        dfs(0,temp,vis,graph);
        return ans;
    }
};