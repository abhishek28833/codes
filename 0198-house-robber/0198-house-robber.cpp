class Solution {
public:
    int rec(vector<int>& arr,int i,vector<int>& dp){
        if(i==0) return arr[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int a =0,b=0;
        a = arr[i] + rec(arr,i-2,dp);
        b = rec(arr,i-1,dp); 
        return dp[i] = max(a,b);
        
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return rec(nums,n-1,dp);
    }
};