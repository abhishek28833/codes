class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& a: mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};