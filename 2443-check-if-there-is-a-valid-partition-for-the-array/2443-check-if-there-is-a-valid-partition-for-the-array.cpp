class Solution {
public:
    int rec(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i==n-1){
            return 0;
        }
        if(i==n) return 1;
        if(i==n-2 && nums[i]!=nums[i+1]) return 0;

        if(dp[i]!=-1) return dp[i];

        if(nums[i]==nums[i+1]){
            if(rec(nums,i+2,n,dp)){
                return dp[i] = 1;
            }
        }
        if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
            if(rec(nums,i+3,n,dp)){
                return dp[i] = 1;
            }
        }
        if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
            if(rec(nums,i+3,n,dp)){
                return dp[i]=1;
            }
        }
        return dp[i] = 0;

    }


    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return rec(nums,0,n,dp);
    }
};