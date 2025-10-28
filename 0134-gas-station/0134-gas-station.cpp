class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int start=0;
        int gassum=0;
        int costsum=0;
        for(int i=0;i<gas.size();i++){
            gassum+=gas[i];
            costsum+=cost[i];
        }
        if(gassum<costsum) return -1;
        for(int j=0;j<gas.size();j++){
          total+=gas[j]-cost[j];
          if(total<0){
            total=0;
            start=j+1;
          }
        }
        return start;
    }
};