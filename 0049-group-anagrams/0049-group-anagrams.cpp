class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto a: mp){
            vector<string> temp;
            for(auto b: a.second){
                temp.push_back(strs[b]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};