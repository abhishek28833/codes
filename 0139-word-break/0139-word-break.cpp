class Solution {
public:
    bool rec(string s,unordered_set<string>& se,unordered_map<string,bool>& dp){
        int n = s.length();
        if(n==0) return true;

        if(dp.count(s)) return dp[s];
        
        for(int i=0;i<n;i++){
            if(se.count(s.substr(0,i+1))){
                if(rec(s.substr(i+1),se,dp))
                return dp[s] = true;
            }
        }
        return dp[s] = false;
        
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(auto a: wordDict){
            se.insert(a);
        }
        unordered_map<string,bool> dp;
        return rec(s,se,dp);
        
    }
};

