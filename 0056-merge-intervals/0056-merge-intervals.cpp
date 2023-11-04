class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n = in.size();
        vector<vector<int>> ans;
        int a = in[0][0];
        int b = in[0][1];
        vector<int> temp;
        for(int i=1;i<n;i++){
            if(in[i][0]<=b){
                b = max(in[i][1],b);
            }
            
            else{
                temp.push_back(a);
                temp.push_back(b);
                ans.push_back(temp);
                temp.clear();
                a = in[i][0];
                b = in[i][1];
            }
        }
        temp.push_back(a);
        temp.push_back(b);
        ans.push_back(temp);
        return ans;
    }
};