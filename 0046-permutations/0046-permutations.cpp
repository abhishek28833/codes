class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> nums,int in){
        if(in>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=in;i<nums.size();i++){
            swap(nums[i],nums[in]);
            dfs(nums,in+1);
            swap(nums[i],nums[in]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        dfs(nums,0);
        return ans;

    }
};