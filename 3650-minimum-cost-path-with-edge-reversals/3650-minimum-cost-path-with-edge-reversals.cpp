class Solution {
public:
    int dijkstra(vector<vector<pair<int,int>>>& adj,int n,vector<vector<pair<int,int>>>& mp,int src){
        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // cout<<"dis: "<<dis<<" node: "<<node<<"\n";

            for(auto it: adj[node]){
                int x = it.first;
                int w = it.second;
                if(dist[x] <= dis + w) continue;

                dist[x] = dis+w;
                pq.push({dist[x],x});
            }

            for(auto it: mp[node]){
                int x = it.first;
                int w = it.second;
                if(x == node) continue;

                if(dist[x] <= (2*w) + dis) continue;

                dist[x] = (2*w) + dis;
                pq.push({dist[x],x});
            }

        }

        return (dist[n-1] == INT_MAX) ? -1:dist[n-1];

    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n),mp(n);

        for(auto a: edges){
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v,w});
            mp[v].push_back({u,w});
        }

        return dijkstra(adj,n,mp,0);

    }
};