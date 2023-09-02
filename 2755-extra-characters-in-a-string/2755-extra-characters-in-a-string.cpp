class Solution {
public:
    int rec(string s,unordered_set<string>& se,int n,int i,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi = n;
        string str = "";
        for(int j=i;j<n;j++){
            str += s[j];
            int len = str.size();
            if(se.count(str)){
                len = 0;
            }
            int a = rec(s,se,n,j+1,dp);
            maxi = min(maxi,len+a);
        }
        return dp[i] = maxi;
    }


    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> se;
        for(auto a:dictionary){
            se.insert(a);
        }
        int n = s.length();
        vector<int> dp(n+1,-1);
        return rec(s,se,n,0,dp);;
    }
};