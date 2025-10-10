/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* dfs(Node* old,auto &mpp){
        Node* newy=new Node(old->val); //dfs function to clone node
        mpp[old]=newy;
         for(auto it:old->neighbors){
            if(mpp.find(it)==mpp.end()) (newy->neighbors).push_back(dfs(it,mpp));
            else 
                (newy->neighbors).push_back(mpp[it]);
        }
    return newy;
}
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*>mpp; //old,new
        return dfs(node,mpp);
    }
};