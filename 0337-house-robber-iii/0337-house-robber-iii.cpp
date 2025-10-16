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
int ans=INT_MIN;
unordered_map<TreeNode*, int>mpp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        if(mpp.find(root)!=mpp.end()) return mpp[root];
        int take=root->val;
        if(root->left!=NULL)
            take+=rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL) 
            take+=rob(root->right->left)+rob(root->right->right);
        int not_take=rob(root->left)+rob(root->right);
        ans=max({ans,take,not_take});
        return mpp[root]=max(take,not_take);
    }
};