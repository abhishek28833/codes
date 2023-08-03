class Solution {
public:
    vector<string> mp = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> ans;
    void dfs(int i,string digits,int n,string str){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        if(i==n){
            return;
        }
        int k = mp[digits[i] - '0'].size();
        for(int j=0;j<k;j++){
            str += mp[digits[i] - '0'][j];
            dfs(i+1,digits,n,str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return ans;
        dfs(0,digits,n,"");
        return ans;
    }
};