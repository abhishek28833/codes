class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> adj(n);
        int k = roads.size();
        for(int i=0;i<k;i++){
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = adj[i].size();
                int y = adj[j].size();
                if(adj[i].count(j)){
                    ans = max(ans,x+y-1);
                }
                else{
                    ans = max(ans,x+y);
                }
                
            }
        }
        return ans;
    }
};