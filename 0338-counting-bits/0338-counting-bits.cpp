class Solution {
public:
    int rec(int n,vector<int>& dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int k = log2(n);
        int a = 1 + rec(n-(pow(2,k)),dp);
        return dp[n] = a;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            ans.push_back(rec(i,dp));
        }
        return ans;
    }
};