class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> se;
        for(int i=0;i<n;i++){
            if(se.count(nums[i])) return nums[i];
            se.insert(nums[i]);
        }
        return 0;
    }
};
//  15-12