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
        if(n==1) return nums[0];
        vector<int> a,b;
        for(int i=0;i<n;i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }
        vector<int> dp1(n,-1),dp2(n,-1);
        return max(rec(a,n-2,dp1),rec(b,n-2,dp2));
    }
};