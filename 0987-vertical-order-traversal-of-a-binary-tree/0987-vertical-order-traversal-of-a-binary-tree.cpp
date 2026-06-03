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
    void preorder(TreeNode* node,map<int,vector<pair<int,int>>>& mp,int row,int col){
        if(node == NULL) return;
        mp[col].push_back({row,node->val});
        preorder(node->left,mp,row+1,col-1);
        preorder(node->right,mp,row+1,col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> ans;
        preorder(root,mp,0,0);
        for(auto& a: mp){
            sort(a.second.begin(),a.second.end());
            vector<int> temp;
            for(auto& b: a.second) temp.push_back(b.second);
            ans.push_back(temp);
        }
        return ans;
    }
};