class Solution {
public:
    int rec(vector<vector<int>>& dun,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1){
            if(dun[i][j]>0) return 1;
            else return 1-dun[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        int a = rec(dun,i+1,j,n,m,dp);
        int b = rec(dun,i,j+1,n,m,dp);
        ans = min(ans,min(a,b));
        
        if(ans - dun[i][j] < 1) return dp[i][j] = 1;
        else return dp[i][j] = ans - dun[i][j];

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return rec(dungeon,0,0,n,m,dp);
    }
};
