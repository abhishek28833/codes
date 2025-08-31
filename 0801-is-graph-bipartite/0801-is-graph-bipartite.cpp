class Solution {
public:
    bool colour(queue<pair<int,int>>& q,vector<vector<int>>& graph,vector<int>& arr){
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            for(auto it: graph[a.first]){
                // cout<<it<<" "<<arr[it]<<" "<<a.second<<"\n";
                if(arr[it] != -1 && arr[it] == a.second) return false;
                if(arr[it] == -1){
                    arr[it] = ((!a.second)& 1);
                    q.push({it,arr[it]});
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> arr(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i] == -1){
                arr[i] = 0;
                queue<pair<int,int>> q;
                q.push({i,0});
                if(!colour(q,graph,arr)){
                    return false;
                }
            }
        }
        return true;
    }
};