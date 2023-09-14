class Solution {
public:
    vector<string> ans;
    bool dfs(string node,vector<string>& path,int n,unordered_map<string,vector<string>>& adj){
        path.push_back(node);
        if(path.size()==n+1){
            ans = path;
            return true;
        }
        int si = adj[node].size();
        for(int i=0;i<si;i++){
            string to = adj[node][i];
            adj[node].erase(adj[node].begin()+i);
            if(dfs(to,path,n,adj)){
                return true;
            }
            adj[node].push_back(to);
            sort(adj[node].begin(),adj[node].end());
        }
        path.pop_back();
        return false;
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for(auto& a:adj){
            sort(a.second.begin(),a.second.end());
        }
        vector<string> path;
        dfs("JFK",path,n,adj);
        return ans;
    }
};