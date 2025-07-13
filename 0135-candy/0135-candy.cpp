class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int>left(n,1);
       vector<int>right(n,1);
       for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){ //from 1 to n interation
        left[i]=left[i-1]+1;
        // cout<<left[i];
        }
        if(ratings[n-1-i]>ratings[n-i]){
            right[n-1-i]=right[n-i]+1;
            // cout<<right[i]<<" ";
        }
       } 
       int sum=0;
       for(int i=0;i<n;i++){
        int maxi=max(left[i],right[i]);
        // cout<<maxi<<" ";
        sum+=maxi;
       }
       return sum;
    }
};