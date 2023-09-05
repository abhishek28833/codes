class Solution {
public:
    set<vector<int>> ans;
    void back(vector<int>& nums,int i,vector<int> temp){
        if(i==nums.size()){
            return;
        } 
        temp.push_back(nums[i]);
        ans.insert(temp);
        back(nums,i+1,temp);
        temp.pop_back();
        back(nums,i+1,temp);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        ans.insert(temp);
        back(nums,0,temp);
        vector<vector<int>> final;
        for(auto a:ans){
            final.push_back(a);
        }
        return final;
    }
};