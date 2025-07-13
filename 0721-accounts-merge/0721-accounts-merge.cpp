class Disjointset{
    public:
    vector<int>parent,size;
    //parameterised constructor
    Disjointset(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        size.resize(n+1,1);
    }
    //member functions
    int findUparent(int u){
        if(parent[u]==u) return u; //
        return parent[u]=findUparent(parent[u]);
    }
    void unioinbysize(int u,int v){
        int ulp_u=findUparent(u);
        int ulp_v=findUparent(v);
        if(ulp_u==ulp_v) return; //edge case(u forgot this before)
        if(size[ulp_u]>size[ulp_v]){
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else{ //if u dont write edge case then this case would be executed for same Ultimate parents,so it is imp to write edge case
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mpp; //string,ind
        int n=accounts.size();
        Disjointset ds(n);
        for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            if(mpp.find(accounts[i][j])==mpp.end()) mpp[accounts[i][j]]=i;
            else{
                ds.unioinbysize(i,mpp[accounts[i][j]]);
            }
        }
        }
    //     unordered_set<int>st;
    //     for(int i=0;i<n;i++){
    //         st.insert(ds.findUparent(i));
    //     }
    //     int m=st.size();
    //    vector<vector<string>>ans(m);
       vector<vector<string>>temp(n);
       for(auto it:mpp){
        string s=it.first;
        int ind=it.second;
        temp[ds.findUparent(ind)].push_back(s);
       }
        vector<vector<string>>ans;
       for(int i=0;i<n;i++){
            if(temp[i].size()==0) continue;
            vector<string>t;
            t.push_back(accounts[i][0]);
            sort(temp[i].begin(),temp[i].end()); //sort emails first before pushing into final ans
            for(int j=0;j<temp[i].size();j++){
                t.push_back(temp[i][j]);
            }
            ans.push_back(t);
       }
        return ans;
    }
};