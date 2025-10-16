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
int maxi=INT_MIN; //global maxi
int f(TreeNode* &root){ //&maxi basically gives access to modify original maxi 
     if(root==NULL) return 0;
        //call left
        int left=max(0,f(root->left));
        int right=max(0,f(root->right));
        //maxi gets updated in left and right as well and finally at root
        maxi=max(root->val+left+right,maxi);
        return root->val+max(left,right);
}
    int maxPathSum(TreeNode* root) {
        // int maxi=INT_MIN;
        f(root); //maxi will be modified as u passed with adress (&)
        return maxi;
    }
};