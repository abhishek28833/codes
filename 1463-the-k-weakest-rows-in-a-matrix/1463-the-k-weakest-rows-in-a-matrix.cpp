class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> arr;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mp.count(i)) mp[i] = 0;
                if(mat[i][j] == 1) mp[i]++;
            }
        }
        for(auto a:mp){
            arr.push_back({a.second,a.first});
        }
        sort(arr.begin(),arr.end());
        int i=0;
        vector<int> ans;
        while(i!=k){
            ans.push_back(arr[i].second);
            i++;
        }
        return ans;
    }
};