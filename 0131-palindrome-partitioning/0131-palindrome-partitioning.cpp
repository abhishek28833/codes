class Solution {
public:
bool ispalin(string s,int i,int j){
    string str1 = s.substr(i,j-i+1);
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    return str1==str2;
}
vector<vector<string>> ans;
    void rec(string s,int i,vector<string>& curr){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(ispalin(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                rec(s,j+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        rec(s,0,curr);
        return ans;
        
    }
};