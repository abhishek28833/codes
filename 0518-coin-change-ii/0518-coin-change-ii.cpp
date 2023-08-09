class Solution {
public:
    int rec(int amt,vector<int>& coins,int n,int i,vector<vector<int>>& dp){
        if(amt==0) return 1;
        if(amt<0) return 0;

        if(dp[i][amt]!=-1) return dp[i][amt];
        
        int a = 0;
        for(int j=i;j<n;j++){
            a += rec(amt-coins[j],coins,n,j,dp);
        }
        return dp[i][amt]=a;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return rec(amount,coins,n,0,dp);
    }
};