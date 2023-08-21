class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n==1) return false;
        for(int i=0;i<n/2;i++){
            string str = "";
            string add = s.substr(0,i+1);
            while(str.size()<n){
                str += add;
                if(s==str) return true;
            }
            if(s==str) return true;
        }
        return false;
    }
};