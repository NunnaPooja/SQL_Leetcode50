class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       //already sorted in ascending order
      vector<vector<int>>ans;
      int n=intervals.size();
      if(n==0){ //for an empty 
        ans.push_back(newInterval);
        return ans;
      }
      int i=0;
      while(i<n && newInterval[0]>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
            while(i<n && !(newInterval[0]>intervals[i][1]||newInterval[1]<intervals[i][0])){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
            }
            cout<<newInterval[0]<<" ";
            cout<<newInterval[1]<<" ";
       ans.push_back(newInterval); 
       
      while(i<n){
        ans.push_back(intervals[i]);
        i++;
      }
      return ans; 
    }
};