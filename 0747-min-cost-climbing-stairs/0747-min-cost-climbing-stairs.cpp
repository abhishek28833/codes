class Solution {
public:
int solve(int i,vector<int>& cost,vector<int>& dp){
    if(i<=1) return 0;

    if(dp[i]!=-1) return dp[i];

    int left = solve(i-1,cost,dp) + cost[i-1];
    int right = solve(i-2,cost,dp) + cost[i-2];

    return dp[i] = min(left,right);
}

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,cost,dp);
    }
};