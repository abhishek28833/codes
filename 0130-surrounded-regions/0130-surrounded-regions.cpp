class Solution {
public:
    int d1[4] = {0,0,-1,1};
    int d2[4] = {-1,1,0,0};
    void dfs(vector<vector<char>>& board,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(board[i][j]=='X' || board[i][j]=='D') return;
        board[i][j] = 'D';
        for(int k=0;k<4;k++){
            dfs(board,i+d1[k],j+d2[k],n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]!='X'){
                    dfs(board,i,j,n,m);
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] =='D'){
                    board[i][j] = 'O';
                }
            
            }
        }
    }
};