class Solution {
public:
    bool check(string& s,int n){
        int i=0,j=n-1,cnt = 0,idxi = -1,idxj=-1;
        while(i<j){
            // cout<<"i: "<<i<<" j: "<<j<<" cnt: "<<cnt<<"\n";
            if(s[i]==s[j]) i++,j--;
            else{
                if(cnt == 0){
                    idxi = i;
                    idxj = j;
                    i++;
                }else if(cnt == 1){
                    j = idxj - 1;
                    i = idxi;
                }
                cnt++;
            }
            if(cnt > 2) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        return check(s,n);
    }






};