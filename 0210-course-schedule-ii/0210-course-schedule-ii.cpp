class Solution {
public:
vector<int>toposort(int n,vector<vector<int>>&adjlist){
    vector<int>ans;
        queue<int>q;
        vector<int>indegrees(n,0);
        for(int i=0;i<n;i++){
           for(auto it:adjlist[i]){
               indegrees[it]++;
           } 
        }
        //add node with indegrees=0 into the queue
       for(int i=0;i<n;i++){
           if(indegrees[i]==0) q.push(i);
       } 
       while(!q.empty()){
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto it: adjlist[node]){
               //remove the edge between node and adj nodes
               indegrees[it]--;
               if(indegrees[it]==0) q.push(it); //if adj nodes has no indegrees it means it can be added to queue for 
               //being in topo sort order
           }
       }
       return ans;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         //numCouses is the no.of vertices or say no.of nodes
        vector<vector<int>> adjlist(numCourses); 
        vector<int>ans;
        for(auto it:prerequisites){
           adjlist[it[1]].push_back(it[0]);
           /*Using it.first and it.second won't work because 'it' is a vector<int>, not a pair<int, int>.*/
        }
        vector<int>topo= toposort(numCourses,adjlist);
        if(topo.size()<numCourses) return ans; //if the toposort size is anywhere less than no.of nodes
        //it means that would be coz of cycle and problem statement given that u need to return empty string
        return topo;
    }
};