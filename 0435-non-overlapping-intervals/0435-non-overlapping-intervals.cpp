bool comp(vector<int>&v1,vector<int>&v2){
    return (v1[1]<v2[1]); //always sort on end time(not start time) for intervals merge,non overlap problems
    //u can ignore tiebreaker
    /*If a problem only asks for a count (like how many intervals to remove,
     how many are non-overlapping, etc.), then:
Tie-breaking in sorting is not critical.*/
/*But if the problem asks to return the actual intervals (e.g., after merging or selecting), then:
Tie-breakers in sorting matter.
Why? Because the order determines:
Which intervals get merged first.
Which intervals are selected when there’s a conflict.
Whether overlapping is handled correctly.*/

}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //add non merging intervals and return n-non merging intervals
        // vector<vector<int>>ans; no need of vector to store intervals as we just need to return the cnt
        sort(intervals.begin(),intervals.end(),comp); //sort on basis of end time
         int n=intervals.size();
        // for(int i=0;i<n;i++){
        //      cout<<intervals[i][0]<<"p0 ";
        //         cout<<intervals[i][1]<<"p1 ";
        // }
        int cnt=1;
        int premax=intervals[0][1];
        for(int i=1;i<n;i++){
           if(intervals[i][0]>=premax){ //as all u care is cnt so no need to store it in ans vector
             cnt++;
           premax=intervals[i][1];
           }
        }
        return n-cnt;
    }
};
/* [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]*/