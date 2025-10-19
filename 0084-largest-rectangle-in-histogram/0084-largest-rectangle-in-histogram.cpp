class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int el,nse,pse;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                el=st.top();st.pop();
                nse=i;
                pse=st.empty()? -1: st.top();
                maxi=max(maxi,heights[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            el=st.top();st.pop();
            nse=n;
            pse=st.empty()? -1: st.top();
            maxi=max(maxi,heights[el]*(nse-pse-1));
        }
        return maxi;
    }
};