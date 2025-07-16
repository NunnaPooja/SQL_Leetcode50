bool comp(vector<int>&v1,vector<int>&v2){
    if(v1[0]<v2[0]) return true;
    else if(v1[0]==v2[0]) return v1[1]>v2[1];
    return false;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        int cnt=1;
        //sort envelops on basis of width and if same width, sort on basis of descending order of heights
        sort(envelopes.begin(),envelopes.end(),comp);
        //  for(int i=0;i<n;i++){
        //     cout<<envelopes[i][0]<<"p0 ";
        //     cout<<envelopes[i][1]<<"p1 ";
        //  }
        // int maxw=envelopes[0][0];
        // int maxh=envelopes[0][1];
        // for(int i=1;i<n;i++){
        //     if(envelopes[i][0]>maxw && envelopes[i][1] >maxh){
        //         maxw=envelopes[i][0]; //update maxw
        //         maxh=envelopes[i][1]; //update maxh
        //         cnt++;
        // }
        // }
        /*This code checks whether both width and height 
        are strictly increasing compared to the current maxw and maxh.
         That means it's trying to greedily find a strictly increasing sequence — but not necessarily the longest one.*/
        // return cnt;
        // LIS on heights
        // vector<int>temp;
        // for(auto it:envelopes){
        //    temp.push_back(it[1]);
        // } //no need to this temp, we can directly iterate on envelopes array and apply lis on heights
        //binary search on ans for LIS
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int lbindex=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[lbindex]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};