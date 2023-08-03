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
    int rec(TreeNode* root,unordered_map<TreeNode*,int>& dp){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        if(dp.count(root)){
            return dp[root];
        }
        
        int a = root->val,b=0;
        if(root->left){
            a += rec(root->left->left,dp) + rec(root->left->right,dp);
        }
        if(root->right){
            a += rec(root->right->right,dp) + rec(root->right->left,dp);
        }
        b = rec(root->left,dp) + rec(root->right,dp);

        return dp[root] = max(a,b);

    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return rec(root,dp);
    }
};