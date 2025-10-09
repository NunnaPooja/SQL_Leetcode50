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
void f(TreeNode* root,int targetSum,vector<int>&temp,vector<vector<int>>&ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL &&root->val==targetSum){
        temp.push_back(root->val);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
        temp.push_back(root->val);
        f(root->left,targetSum-root->val,temp,ans);
        f(root->right,targetSum-root->val,temp,ans);
        temp.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(root,targetSum,temp,ans);
        return ans;
    }
};