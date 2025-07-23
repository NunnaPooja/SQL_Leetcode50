class Solution {
public:
bool check(int mid,int maxi,vector<int>&piles){
    double time=0;
    for(int i=0;i<piles.size();i++){
        time+=ceil((double)piles[i]/(double)mid);
        if(time>maxi) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=0;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,h,piles)){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};