class Solution {
public:
    int d1[4] = {0,0,-1,1};
    int d2[4] = {-1,1,0,0};
    int dfs(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int a = 0,maxi =0;
        for(int k=0;k<4;k++){
            int row = i+d1[k];
            int col = j+d2[k];
            if(row>=0 && col>=0 && row<n && col<m){
                if(matrix[row][col]>matrix[i][j]){
                    a = 1 + dfs(matrix,n,m,row,col,dp);
                    
                    maxi = max(a,maxi);
                }
            }
        }
        return dp[i][j] = maxi;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a = dfs(matrix,n,m,i,j,dp);
                maxi = max(maxi,a+1);
            }
        }
        return maxi;

    }
};