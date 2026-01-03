class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ind = -1;
        for(int i=n-1;i>=0;i--){
            if(mp.count(nums[i])){
                ind = i;
                break;
            }
            mp[nums[i]]++;
        }

        if(ind == -1) return 0;
        return (ind/3)+1;
    }
};