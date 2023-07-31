class Solution {
public:
    long long rec(vector<int>& coins,int amount,int i,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(i==0 && amount==coins[i]) return 1;
        if(i==0 && amount<coins[i]) return INT_MAX;
        if(i<0) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        long long a=INT_MAX,b=INT_MAX;
        if(amount>=coins[i])
        a = 1 + rec(coins,amount-coins[i],i,dp);
        b = rec(coins,amount,i-1,dp);

        return dp[i][amount] = min(a,b);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        long long a = rec(coins,amount,n-1,dp);
        if(a!=INT_MAX) return a;
        return -1;
    }
};