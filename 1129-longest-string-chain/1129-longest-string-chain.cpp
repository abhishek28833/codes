class Solution {
public:
    int rec(vector<string>& words,int n,string prev,unordered_map<string,int>& dp){
        if(dp.count(prev)) return dp[prev];
        int a=0,maxi=0;
        for(int i=0;i<n;i++){
            if(words[i].size() == prev.size()+1){
                int k=0;
                for(int j=0;j<words[i].size();j++){
                    if(words[i][j]!=prev[k]){
                        string temp = words[i];
                        temp.erase(j,1);
                        if(temp == prev){
                            a = 1 + rec(words,n,words[i],dp);
                        }
                    }
                    else k++;
                }
            }
            maxi = max(a,maxi);
        }
        return dp[prev] = maxi;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 0;
        unordered_map<string,int> dp;
        for(int i=0;i<n;i++){
            maxi = max(maxi, rec(words,n,words[i],dp));
        }
        return maxi+1;
    }
};