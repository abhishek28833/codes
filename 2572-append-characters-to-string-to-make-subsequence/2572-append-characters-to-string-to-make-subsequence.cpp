class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(),i=-1,m = t.size();
        for(int j=0;j<m;j++){
            while(i<n){
                i++;
                if(s[i]==t[j]){
                    break;
                }
            }
            if(i==n) return m-j;
        }
        return 0;
    }
};