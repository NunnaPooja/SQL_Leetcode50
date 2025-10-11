class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revadj(n);
        vector<int>ans;
        vector<int>indegrees(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                revadj[it].push_back(i);
                indegrees[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegrees[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            ans.push_back(node);
            q.pop();
            for(auto it:revadj[node]){
                indegrees[it]--;
                if(indegrees[it]==0) q.push(it);
            }
        }
        // if(cnt==0) return {};
        sort(ans.begin(),ans.end()); //u can apply sort onto empty vector as well
        return ans;
    }
};