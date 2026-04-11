class Solution {
public:

    int fn(vector<int>& cuts,int low,int high,vector<vector<int>>& dp){
        if(low >= high) return 0;
        if(dp[low][high] != -1) return dp[low][high];
        int mini = INT_MAX;
        for(int i=low+1;i<high;i++){
            int x = cuts[high] - cuts[low] + fn(cuts,low,i,dp) + fn(cuts,i,high,dp);
            mini = min(mini,x);
        }
        return dp[low][high] = (mini != INT_MAX) ? mini : 0;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int> (m+1,-1));
        return fn(cuts,0,cuts.size()-1,dp);
    }
};