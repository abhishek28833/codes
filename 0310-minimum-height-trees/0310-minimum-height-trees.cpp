class Solution {
public:
    int bfs(vector<vector<int>>& adj,int root){
        int hei = 0;
        queue<pair<int,int>> q;
        q.push({root,-1});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int parent = q.front().second;
                int node = q.front().first;
                q.pop();
                int si = adj[node].size();
                for(int j=0;j<si;j++){
                    if(adj[node][j]!=parent){
                        q.push({adj[node][j],node});
                    }
                }
            }
            hei++;
        }
        return hei;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int> {0};
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            ind[edges[i][0]]++;
            ind[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            ans.clear();
            for(int i=0;i<n;i++){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto a:adj[node]){
                    ind[a]--;
                    if(ind[a]==1) q.push(a);
                }
            }
        }
        return ans;
    }
};