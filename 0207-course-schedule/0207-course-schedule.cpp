class Solution {
public:
    bool bfs(vector<vector<int>>& adj,int node,int n,vector<int>& vis){
        for(auto a: adj[node]){
            if(vis[a] == -1) continue;
            if(vis[a] == 1) return false;
            vis[a] = 1;
            if(!bfs(adj,a,n,vis)) return false;
            vis[a] = -1;
        }
        
        return true;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(auto a: pre){
            adj[a[0]].push_back(a[1]);
        }

        vector<int> vis(num,0);
        for(int i=0;i<num;i++){
            if(!bfs(adj,i,num,vis)) return false;
        }
        return true;

    }
};