class Solution {
public:
    bool checkPali(string& s,int n){
        int i=0,j=n-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void rec(vector<vector<string>>& ans, string s,int i,vector<string>& curr,int n){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        for(int j=i;j<n;j++){
            string str = s.substr(i,j-i+1);
            if(checkPali(str, j-i+1)){
                curr.push_back(str);
                rec(ans,s,j+1,curr,n);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        rec(ans,s,0,curr,n);
        return ans;
    }
};