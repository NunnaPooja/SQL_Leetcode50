/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cam=0;
    int dfs(TreeNode* root) {
        //greedy dfs
        //post order dfs left->right->root
        //base case
        if(root==NULL) return 0; //null node is already covered and doesnot need cam
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==-1 || r==-1){ //if either of children is covered with cam
            //then we must place camera at parent
            cam++;
            return 1; //cam placed
        }
        if(l==1 || r==1){ //either of children has camera,current node is covered
            return 0; //covered but doesn has cam
        }
        //if childs are just covered then notify parent that it needs cam
        else{
            return -1; //basically leaf node will return -1,meaning parent is placed camera
        }
    }
    int minCameraCover(TreeNode* root){
        if(root==NULL) return 0;
        if(dfs(root)==-1) cam++; //if parent 
        return cam;
    }
};