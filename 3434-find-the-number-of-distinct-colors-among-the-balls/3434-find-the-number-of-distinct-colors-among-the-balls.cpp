class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        map<int,int> mp,mpp;
        
        for(auto a:queries){
            int ind = a[0];
            int col = a[1];
            if(!mpp.count(ind)){
                mp[col]++;
                mpp[ind] = col;
                ans.push_back(mp.size());
            }
            else{
                int pcol = mpp[ind];
                mp[pcol]--;
                if(mp[pcol]==0){
                    mp.erase(pcol);
                }
                mp[col]++;
                mpp[ind] = col;
                ans.push_back(mp.size());
            }
        }
        return ans;
    }
};