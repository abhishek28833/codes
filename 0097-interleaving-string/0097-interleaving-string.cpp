class Solution {
public:
    int rec(string& s1,string& s2,string& s3,int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(k==s3.length()){
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if(i<s1.size() && s1[i]==s3[k] && rec(s1,s2,s3,i+1,j,k+1,dp)){
            return dp[i][j][k] = 1;
        }
        if(j<s2.size() && s2[j]==s3[k] && rec(s1,s2,s3,i,j+1,k+1,dp)){
            return dp[i][j][k] = 1;
        }

        return dp[i][j][k] = 0;
    }
    

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n = s1.size(),m = s2.size(),k=s3.size();
        vector<vector<vector<int>>> dp (n+1,vector<vector<int> >(m+1,vector <int>(k+1,-1)));
        return rec(s1,s2,s3,0,0,0,dp);
    }
};