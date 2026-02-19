class Solution {
public:
    unordered_map<int,bool> dp;
    bool rec(string& s,int n,int i,unordered_set<string>& se){
        if(i == n){
            return true;
        }

        // cout<<str<<" ";

        if(dp.count(i)) return dp[i];

        string str = "";
        for(int j=i;j<n;j++){
            str.push_back(s[j]);
            if(se.count(str)){
                if(rec(s,n,j+1,se)) return dp[i] = true;
            }
        }

        return dp[i] = false;
        
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(auto a: wordDict){
            se.insert(a);
        }
        return rec(s,s.size(),0,se);

    }
};