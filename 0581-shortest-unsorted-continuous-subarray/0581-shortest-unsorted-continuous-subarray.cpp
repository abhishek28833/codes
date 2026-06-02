class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1,right = -1,n = nums.size(),maxi = nums[0],mini = nums[n-1];
        
        for(int i=1;i<n;i++){
            maxi = max(nums[i],maxi);
            if(maxi > nums[i]) right = i;
        }

        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            if(mini < nums[i]) left = i;
        }
        
        return left == -1 ? 0 : right-left+1;
    }
};