class Solution {
public:
    vector<int> di(vector<vector<pair<int,int>>>& adj, int node){
        vector<int> dist(26,INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node});
        dist[node] = 0;
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int ele = pq.top().second;
            pq.pop();

            for(auto it: adj[ele]){
                int x = it.first;
                int y = it.second;
                if(dist[x] <= dis+y) continue;

                dist[x] = dis+y;
                pq.push({dist[x],x});
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        int si = cost.size();
        for(int i=0;i<si;i++){
            int a = original[i]-'a';
            int b = changed[i] -'a';
            int w = cost[i];
            // cout<<a<<" "<<b<<" "<<w<<"\n";
            adj[a].push_back({b,w});
        }

        // printAdj(adj);

        unordered_map<int,vector<int>> mp;
        for(int i=0;i<26;i++){
            mp[i] = di(adj,i);
        }

        long long tcost = 0,n = source.size();

        for(int i=0;i<n;i++){
            int s = source[i]-'a';
            int d = target[i] - 'a';
            if(mp[s][d] == INT_MAX) return -1;
            tcost += mp[s][d];
        }
        return tcost;
    }
};