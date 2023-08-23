class Solution {
public:
    vector<int> ans;
    int dfs(unordered_map<int,vector<int>>& mp,vector<int>& vis,int i,vector<int>& pushed){
        if(pushed[i]==1) return 1;
        if(mp[i].size()==0){
            // cout<<i<<" ";
            ans.push_back(i);
            vis[i] = 1;
            pushed[i] = 1;
            return 1;
        }  
        if(vis[i]==1) return 0;
        vis[i] = 1;

        for(auto a:mp[i]){
            if(dfs(mp,vis,a,pushed)==0)
            return 0;
        }
        ans.push_back(i);
        pushed[i] = 1;
        return 1;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<numCourses;i++){
            mp[i] = vector<int>();
        }
        for(auto a:pre){
            mp[a[0]].push_back(a[1]);
        }

        vector<int> pushed(numCourses,0);
        for(int i=0;i<numCourses;i++){
            vector<int> vis(numCourses,0);
            if(pushed[i]==0){
                if(dfs(mp,vis,i,pushed)==0){
                    return vector<int>();
                }
            }
            
        }
        return ans;

    }
};