class Solution {
public:
vector<int>colors;
vector<int>vis;
void f(int node,vector<vector<int>>&adj){
    vis[node]=1;
    //below code will fail one node can be neighbour to more than one node
    // for(auto neigh: adj[node]){
    //     if(!vis[neigh]){
    //         cout<<neigh;
    //         for(int i=1;i<=4;i++){
    //             if(i!=clr){
    //                 f(neigh,i,adj);
    //                 break;
    //             }
    //         }
    //     }
    //     else {
    //         if( colors[neigh]==clr){
    //         for(int i=1;i<=4;i++){
    //             if(i!=clr) {
    //                 cout<<i;
    //                 colors[node]=i;
    //                 break;
    //         }
    //     }
    //         }
    // }
// }
bool used[5]={false};
for(int neigh:adj[node]){
    if(colors[neigh]!=0) used[colors[neigh]]=true; //check adj nodes colors
}
for(int c=1;c<=4;c++){
    if(!used[c]) colors[node]=c; //assign least color to current node
}
for(auto neigh:adj[node]){
    if(colors[neigh]==0) f(neigh,adj); //call dfs for neighbors which are not colored
}
}
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto it:paths){
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        colors.resize(n,0);
        vis.resize(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                f(i,adj);
        }
        return colors;
    }
};