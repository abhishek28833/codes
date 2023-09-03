class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0) dp[i][j] =1;
                if(j==0) dp[i][j] = 1;
            }
        }
        int a =0,b=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
        
    }
};