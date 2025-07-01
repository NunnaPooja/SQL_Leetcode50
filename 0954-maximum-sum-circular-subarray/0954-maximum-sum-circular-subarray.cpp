class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int n=nums.size();
        //kadens alh]go for max sum
        for(auto num:nums){
            sum=max(sum+num,num); //take current num if sum<0
            maxi=max(maxi,sum);
        }
        int mini=INT_MAX;
        int totalsum=0;
        sum=0;
        //kadens algo for min sum
        for(auto num:nums){
            sum=min(sum+num,num); //take current num if it negative
            mini=min(mini,sum);
            totalsum+=num;
            //  if(sum>0 &&num<0) sum=0;
        }
        if(maxi<0) return maxi;
        return max(maxi,totalsum-mini);
    }
};