class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a:nums){
            mp[a]++;
        }
        int n = nums.size();
        n = n/3;
        vector<int> ans;
        for(auto a:mp){
            if(a.second>n)ans.push_back(a.first);
        }
        return ans;

    }
};