class Solution {
public:
    vector<vector<int>> ans;
    void rec(int n,int k,vector<int>& temp,int i){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
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
        return ans;
    }
};

