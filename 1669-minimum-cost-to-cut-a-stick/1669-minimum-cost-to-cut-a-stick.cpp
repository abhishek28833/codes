class Solution {
public:
    long long rec(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i+1;k<j;k++){
            int a = (cuts[j] - cuts[i]) + rec(i,k,cuts,dp) + rec(k,j,cuts,dp);
            mini = min(a,mini);
        }
        if(mini!=INT_MAX)
        return dp[i][j] = mini;
        return dp[i][j] = 0;
    }


    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int l = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
        return rec(0,l-1,cuts,dp);

    }
};