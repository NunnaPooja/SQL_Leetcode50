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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL &&root2==NULL) return NULL;
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        TreeNode* newy=new TreeNode();
        newy->left=mergeTrees(root1->left,root2->left);
        newy->right=mergeTrees(root1->right,root2->right);
        newy->val=root1->val+ root2->val; //current node val
        // newy->left=mergeTrees(root1->left,root2->left); //compute left subtree by recursion on left
        // newy->right=mergeTrees(root1->right,root2->right); //compute right tree by recursion on right
        // mergeTrees(root1->right,root2->right);
        return newy;
    }
};