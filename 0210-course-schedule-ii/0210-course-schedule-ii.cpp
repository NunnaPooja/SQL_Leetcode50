class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegrees(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            indegrees[u]++;
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<numCourses;i++){ //indexing till numcourses-1
            if(indegrees[i]==0) q.push(i);
        }
        int cnt=0; //toposort count
        while(!q.empty()){
            auto node=q.front();
            topo.push_back(node);
            cnt++;
            if(cnt==numCourses) return topo;
            q.pop();
            for(auto neig:adj[node]){
                indegrees[neig]--;
                if(indegrees[neig]==0){
                    q.push(neig);
                }
            }
        }
        return {};
    }
};