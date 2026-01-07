class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n; k++){
                    if(k==i || k==j) continue;
                    for(int l=0; l<n; l++){
                        if(l==i || l==j || l==k) continue;
                        // cout<<i<<" "<<j<<" "<<k<<" "<<" "<<l<<"\n";
                        if(words[i][0] == words[j][0] && words[i][3] == words[k][0] && words[j][3] == words[l][0] && words[k][3] == words[l][3]){
                            ans.push_back({words[i],words[j],words[k],words[l]});
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};