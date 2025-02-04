class Solution {
public:
    bool dfs(vector<int>& vis,vector<vector<int>>& pre,int node){
        if(vis[node] == 1) return false;
        if(vis[node] == 2) return true;
        vis[node] = 1;
        for(auto a: pre[node]){
            if(!dfs(vis,pre,a)) return false;
        }
        vis[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto a: prerequisites){
            adj[a[0]].push_back(a[1]);
        }

        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]!=2 && !dfs(vis,adj,i)){
                return false;
            }
        }
        return true;
    }
};