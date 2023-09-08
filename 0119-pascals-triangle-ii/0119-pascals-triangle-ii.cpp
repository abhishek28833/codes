class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> temp = {1};
        ans.push_back(temp);
        if(rowIndex==0) return temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(rowIndex==1) return temp;
        int cnt = 1;
        while(cnt<rowIndex){
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
            if(cnt == rowIndex) return final;
        }
        return temp;
    }
};