class Solution {
public:
    // int dfs(vector<vector<int>>& graph ,vector<int>& vis,int node,vector<int>& cy){
        
    //     vis[node]=1;
    //     cy[node]=1;
    //     for(auto a:graph[node]){
    //         if(vis[a]==0 && dfs(graph,vis,a,cy)) return 1;
    //         else if(cy[a]==1) return 1;
    //     }
    //     cy[node]=0;   
    //     return 0;

    // }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                ind[i]++;
                adj[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            int k = adj[a].size();
            for(int i=0;i<k;i++){
                ind[adj[a][i]]--;
                if(ind[adj[a][i]] == 0){
                    q.push(adj[a][i]);
                    ans.push_back(adj[a][i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};