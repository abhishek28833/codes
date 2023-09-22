class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n==0) return true;
        int i=0,j=0;
        while(j<m){
            if(s[i]==t[j]){
                i++;
                if(i==n) return true;
            }
            j++;
        }
        return false;
    }
};