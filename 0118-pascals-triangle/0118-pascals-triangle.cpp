class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp = {1};
        ans.push_back(temp);
        if(numRows==1) return ans;
        temp.push_back(1);
        ans.push_back(temp);
        int cnt = 1;
        while(cnt<numRows-1){
            int n = ans[cnt].size();
            vector<int> final;
            final.push_back(1);
            for(int i=1;i<n;i++){
                int a = ans[cnt][i] + ans[cnt][i-1];
                final.push_back(a);
            }
            final.push_back(1);
            ans.push_back(final);
            cnt++;
        }
        return ans;
    }
};