class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int node,int n,vector<int>& vis){
        for(auto a: adj[node]){
            if(vis[a] == -1) continue;
            if(vis[a] == 1) return false;
            vis[a] = 1;
            if(!dfs(adj,a,n,vis)) return false;
            vis[a] = -1;
        }
        
        return true;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num,0);
        for(auto a: pre){
            adj[a[0]].push_back(a[1]);
            indegree[a[1]]++;
        }

        stack<int> st;
        int cnt = 0;
        for(int i=0;i<num;i++){
            if(indegree[i] == 0){
                st.push(i);
                cnt++;
            } 
        }

        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            for(auto a: adj[ele]){
                indegree[a]--;
                if(indegree[a] == 0){
                    st.push(a);
                    cnt++;
                } 
            }
        }
        if(cnt == num) return true;
        return false;

    }
};