class Solution {
public:
    vector<string> ans;
    void dfs(unordered_map<char,vector<char>>& mp,int i,string digits,int n,string str){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        if(i==n){
            return;
        }
        int k = mp[digits[i]].size();
        for(int j=0;j<k;j++){
            str += mp[digits[i]][j];
            dfs(mp,i+1,digits,n,str);
            str.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mp;

        mp['2'].push_back('a');
        mp['2'].push_back('b');
        mp['2'].push_back('c');
        mp['3'].push_back('d');
        mp['3'].push_back('e');
        mp['3'].push_back('f');
        mp['4'].push_back('g');
        mp['4'].push_back('h');
        mp['4'].push_back('i');
        mp['5'].push_back('j');
        mp['5'].push_back('k');
        mp['5'].push_back('l');
        mp['6'].push_back('m');
        mp['6'].push_back('n');
        mp['6'].push_back('o');
        mp['7'].push_back('p');
        mp['7'].push_back('q');
        mp['7'].push_back('r');
        mp['7'].push_back('s');
        mp['8'].push_back('t');
        mp['8'].push_back('u');
        mp['8'].push_back('v');
        mp['9'].push_back('w');
        mp['9'].push_back('x');
        mp['9'].push_back('y');
        mp['9'].push_back('z');

        int n = digits.size();
        if(n==0) return ans;
        dfs(mp,0,digits,n,"");
        return ans;
        


    }
};