class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>& vis,int i){
        if(vis[i]==1) return;
        vis[i] = 1;
        int n = rooms[i].size();
        for(int j=0;j<n;j++){
            dfs(rooms,vis,rooms[i][j]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int si = rooms.size();
        vector<int> vis(si,0);
        dfs(rooms,vis,0);
        for(int i=0;i<si;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};