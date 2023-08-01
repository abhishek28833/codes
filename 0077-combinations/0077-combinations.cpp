class Solution {
public:
    set<vector<int>> se;
    void rec(int n,int k,vector<int>& temp,int i){
        if(temp.size()==k){
            se.insert(temp);
        }
        if(i>n) return;
        temp.push_back(i);
        rec(n,k,temp,i+1);
        temp.pop_back();
        rec(n,k,temp,i+1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        rec(n,k,temp,1);
        vector<vector<int>> ans;
        for(auto a:se){
            ans.push_back(a);
        }
        return ans;
    }
};