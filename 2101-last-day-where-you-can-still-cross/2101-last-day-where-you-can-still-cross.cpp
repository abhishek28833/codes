class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& arr,int i,int j,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=row || j>=col) return false;
        if(arr[i][j]==1 || vis[i][j]==1) return false;
        vis[i][j]=1;
        if(i==row-1 && j>=0 && j<col) return true;
        if(dfs(row,col,arr,i+1,j,vis)) return true;
        if(dfs(row,col,arr,i-1,j,vis)) return true;
        if(dfs(row,col,arr,i,j-1,vis)) return true;
        if(dfs(row,col,arr,i,j+1,vis)) return true;
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();

        int ans =0;
        int low =0,high = n-1;
        while(low<=high){
            vector<vector<int>> arr(row,vector<int> (col,0));
            vector<vector<int>> vis(row,vector<int> (col,0));
            int mid = (low+high)/2;
            for(int i=0;i<=mid;i++){
                arr[cells[i][0]-1][cells[i][1]-1] = 1;
                vis[cells[i][0]-1][cells[i][1]-1] =1;
            }
            
            int flag =0;
            for(int k=0;k<col;k++){
                if(dfs(row,col,arr,0,k,vis)){
                ans = mid;
                low = mid+1;
                flag = 1;
                break;
                }
                
            }
            if(flag ==0) 
            high = mid-1;
            


        }
        return ans+1;
    }
};
