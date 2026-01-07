class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        long long ans = 0;
        vector<long long> mp(n,1e15);
        mp[0] = 0;
        for(auto a: restrictions){
            mp[a[0]] = a[1];
        }

        
        for(int i=1;i<n;i++){
            mp[i] = min(mp[i],mp[i-1] + diff[i-1]); 
        }
        for(int i=n-2;i>=0;i--){
            mp[i] = min(mp[i],mp[i+1]+diff[i]);
            ans = max(ans,mp[i]);
        }
        ans = max(ans,mp[n-1]);
        return ans;
    }
};