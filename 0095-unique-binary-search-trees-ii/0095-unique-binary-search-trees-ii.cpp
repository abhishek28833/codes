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
    TreeNode* allocate(int data){
        TreeNode* nn = new TreeNode;
        nn->val = data;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    
    vector<TreeNode*> rec(int st,int end){
        if(st > end) return {NULL};
        if(st == end){
            TreeNode* nn = allocate(st);
            return {nn}; 
        }
        vector<TreeNode*> ans;
        for(int i=st;i<=end;i++){
            vector<TreeNode*> leftbst = rec(st, i-1);
            vector<TreeNode*> rightbst = rec(i+1,end);
            for(auto leftroot : leftbst){
                for(auto rightroot: rightbst){
                    TreeNode* root = allocate(i);
                    root->left = leftroot;
                    root->right = rightroot;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }


    vector<TreeNode*> generateTrees(int n) {
        
        return rec(1,n);
    }
};