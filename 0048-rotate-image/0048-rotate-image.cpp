class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n-i;j++){
                if(vis[i][j]==0){
                    vis[i][j] = 1;
                    int a = matrix[i][j];
                    int t = matrix[j][n-1-i];
                    vis[j][n-1-i] = 1;
                    matrix[j][n-1-i] = a;
                    a = t;
                    t = matrix[n-1-i][n-1-j];
                    vis[n-1-i][n-1-j] = 1;
                    matrix[n-1-i][n-1-j] = a;
                    a = t;
                    t = matrix[n-1-j][i];
                    vis[n-1-j][i] = 1;
                    matrix[n-1-j][i] = a;
                    matrix[i][j] = t;
                }
 
            }
        }

    }
};