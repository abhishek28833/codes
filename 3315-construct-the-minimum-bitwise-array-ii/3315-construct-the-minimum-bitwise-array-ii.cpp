class Solution {
public:
    int findBit(int val){
        int mini = INT_MAX;
        for(int i=0;i<31;i++){
            if((1<<i)&val){
                int x = val;
                x = (x & (~(1<<i)) );
                if( (x|(x+1)) == val){
                    mini = min(mini,x);
                }
                if( (x | (x-1)) == val){
                    mini = min(mini,x-1);
                }
            }
        }
        return (mini == INT_MAX) ? -1 : mini;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(findBit(nums[i]));
        }
        return ans;
    }
};