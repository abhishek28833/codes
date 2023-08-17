class Solution {
public:
    int d1[4] = {0,0,-1,1};
    int d2[4] = {-1,1,0,0};
    void bfs(vector<vector<int>>& mat,queue<pair<pair<int,int>,int>>& q,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& ans){
        
        while(!q.empty()){
            int k = q.size();
            for(int i =0;i<k;i++){
                int r = q.front().first.first,c = q.front().first.second;
                int dir=q.front().second;
                ans[r][c] = dir;
                q.pop();
                for(int j = 0;j<4;j++){
                    int row = r + d1[j];
                    int col = c + d2[j];
                    if( row>=0 && row<n && col>=0 && col<m && vis[row][col]==0){
                        vis[row][col] = 1;
                        q.push({{row,col},dir+1});
                    }
                }
            }
        }
    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        bfs(mat,q,n,m,vis,ans);
        return ans;
    }
};