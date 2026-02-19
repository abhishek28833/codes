class Solution {
public:
    map<pair<string,int>,bool> dp;
    bool rec(string& s,int n, string str,int i,unordered_set<string>& se){
        if(i == n){
            if(se.count(str)) return true;
            return false;
        }

        // cout<<str<<" ";
        if(dp.count({str,i})) return dp[{str,i}];

        bool flag = false;
        if(se.count(str)){
            string stemp(1,s[i]);
            if(rec(s,n,stemp,i+1,se)) flag = true;
        }

        if(rec(s,n,str + s[i],i+1,se)) flag = true;
        return dp[{str,i}] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(auto a: wordDict){
            se.insert(a);
        }
        return rec(s,s.size(),"",0,se);

    }
};