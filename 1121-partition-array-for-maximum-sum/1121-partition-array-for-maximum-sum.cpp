class Solution {
public:
    int rec(vector<int>& arr,int i,int k,int n,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int sum = 0,maxi = INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            maxi = max(maxi,arr[j]);
            sum = max(sum,rec(arr,j+1,k,n,dp)+(j-i+1)*maxi);
        }
        return dp[i] = sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return rec(arr,0,k,n,dp);

    }
};