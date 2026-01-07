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
    long long mod = 1e9 + 7;
    long long ans = 0;

    long long totalSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long maxMultiple(TreeNode* root, long long tSum){
        if(root == NULL){
            return 0;
        }
        long long value = root->val + maxMultiple(root->left,tSum) + maxMultiple(root->right,tSum);
        // cout<<value<<"\n";
        long long temp  = (tSum-value) * value;
        ans = max(ans,temp);
        return value;
    }



    int maxProduct(TreeNode* root) {
        int tsum = totalSum(root);
        // cout<<tsum<<"\n";
        maxMultiple(root,tsum);
        return ans%mod;
    }
};