class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0 || g.size()==0) return 0;
        sort(s.rbegin(),s.rend());
        sort(g.rbegin(),g.rend());
        int n = g.size();
        int ans = 0,j=0;
        for(int i=0;i<n;i++){
            int greed = g[i];
            if(greed <= s[j]){
                ans++;
                j++;
            }
            if(j==s.size()) return ans;
        }
        return ans;

    }
};

