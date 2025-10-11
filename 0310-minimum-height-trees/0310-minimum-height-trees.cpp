class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        //distance from center node is minimises max distance to nodes
        //finding center node using toposort
        vector<int>indegrees(n);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            indegrees[u]++;
            indegrees[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegrees[i]==1) q.push(i);
        }
        int rem=n; //if nodes to process are just 2, then both will be possible root nodes from which max distance is minimised
        //so we directly add them to ans
        //but if we have more than 2 nodes then we process till we get either 1 or 2 nodes left in queue 
        while(rem>2){
        int sz=q.size();
        rem-=sz;
        for(int i=0;i<sz;i++){
            auto node=q.front(); q.pop();
            for(auto neig:adj[node]){
                indegrees[neig]--;
                if(indegrees[neig]==1) q.push(neig);
            }
        }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};