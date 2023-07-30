class Solution {
public:
    int rec(string s,int n,int i,int val,vector<int>& dp){
        // cout<<val<<" "<<i<<"\n";
        if(val > 26 || val ==0) return 0;
        if(i>=n) return 1;
        if(i==n-1){
            if(s[i]=='0') return 0;
            else return 1;
        }
        if(s[i]==0) return 0;
        if(dp[i] != -1) return dp[i];
        int a = 0,b=0;
        
        val = s[i]-48;
        
        a = rec(s,n,i+1,val,dp);
        
        if(i+1<n && val!=0){

            val = val*10;
            val += s[i+1] - 48;
            if(val>9)
            b = rec(s,n,i+2,val,dp);
        }

        return dp[i] = a+b;


    }


    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0') return 0;
        vector<int> dp(n+1,-1);
        return rec(s,n,0,-1,dp);
    }
};