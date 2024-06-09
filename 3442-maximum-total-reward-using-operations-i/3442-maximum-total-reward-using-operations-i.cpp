class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& arr,int i,int sum,int n){
        if(i>=n) return 0;
        if(sum>=2000) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int a = 0,b=0;
        if(arr[i]>sum){
            a = arr[i] + rec(arr,i+1,sum+arr[i],n);
        }
        b = rec(arr,i+1,sum,n);
        return dp[i][sum] = max(a,b);
    }

    int maxTotalReward(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        dp.resize(n+1,vector<int>(2001,-1));
        return rec(arr,0,0,n);
    }
};