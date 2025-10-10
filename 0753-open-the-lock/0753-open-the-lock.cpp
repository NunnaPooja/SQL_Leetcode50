class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>set1(deadends.begin(),deadends.end());
        if(set1.count("0000")) return -1; //if 0000 itself is dead end then we can never reach target
        queue<pair<string,int>>q;
        //string,steps
        q.push({"0000",0});
        unordered_set<string>vis;
        vis.insert("0000");
        while(!q.empty()){
            auto [s,steps]=q.front();
            q.pop();
            if(s==target) return steps;
            for(int i=0;i<4;i++){
                char org=s[i];
                //u can move to only adj digits,not all 9 digits
                for(char dig:{org=='0'? '9' :org-1,org=='9' ? '0' :org+1}){
                    s[i]=dig;
                    if(set1.count(s)<=0 && vis.count(s)<=0){
                        q.push({s,steps+1});
                        vis.insert(s);
                    }
                }
                s[i]=org;
            }
        }
        return -1;
    }
};