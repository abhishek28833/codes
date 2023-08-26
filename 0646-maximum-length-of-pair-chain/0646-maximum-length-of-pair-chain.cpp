class Solution {
public:
    int rec(vector<vector<int>>& pairs,int i,int n,int prev,vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }
        int k = prev;
        if(prev <0){
            k = 1000 - prev;
        }
        if(i==n-1){
            if(pairs[i][0]>prev) return 1;
            else return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int a = 0, b = 0;
        if(pairs[i][0]>prev){
            a = 1 + rec(pairs,i+1,n,pairs[i][1],dp);
        }
        b = rec(pairs,i+1,n,prev,dp);
        return dp[i][k] = max(a,b);
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n,vector<int> (2003,-1));
        return rec(pairs,0,n,-1001,dp);
    }
};