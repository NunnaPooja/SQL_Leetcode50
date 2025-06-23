class DisjointSet{
      vector<int>parent,size;
    public:
    //constructor
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
        int findUparent(int u){
            //backtracking
            if(u==parent[u]) return u;
            return parent[u]=findUparent(parent[u]);
        }
        void unionbysize(int u,int v){
            int ulp_u=findUparent(u);
            int ulp_v=findUparent(v);
            if(ulp_v==ulp_u) return; //ignore the edge if u already had same ultimate parent
            //connect ulp of u to ulp of v if the size of ulp_v >size of ulp_u
            else if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        DisjointSet ds(n);
        int cnt=0;
       int extraedges=0;
       //first build the disjoint set
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUparent(u)==ds.findUparent(v)) extraedges++; //no.of edges between nodes
            else{
                ds.unionbysize(u,v);
            }
        }
        //after the disjoint set being built,count no.of components in graph.
         for(int i=0;i<n;i++){
            if(ds.findUparent(i)==i) cnt++; //no.of nodes to be connected(nodes with parents as itself)
        }
        int ans=cnt-1; //for minimum no.of edges to connect components
        if(extraedges>=ans) return ans;
        return -1;
    }
};