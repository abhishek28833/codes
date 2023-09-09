class Solution {
public:
    int rec(vector<int>& nums,int sum,int n,vector<int>& dp){
        if(sum == 0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        if(dp[sum] != -1) return dp[sum];
        long long a = 0;
        for(int i=0;i<n;i++){
            a += rec(nums,sum-nums[i],n,dp);
        }
        return dp[sum] = a;

    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return rec(nums,target,n,dp);
    }
};
