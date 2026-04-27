class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),ans = INT_MIN,sum=0,mini = INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            mini = max(mini,nums[i]);
            if(sum < 0){
                sum = 0;
            }else{
                ans =  max(ans,sum);
            }
        }
        return ans == INT_MIN ? mini : ans;
    }
};