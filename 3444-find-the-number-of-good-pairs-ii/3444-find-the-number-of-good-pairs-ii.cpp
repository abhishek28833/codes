class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> mp;
        for(auto a:nums1){
            // mp[a]++;
            for(int i=1;i*i<=a;i++){
                if(a%i==0){
                    mp[i]++;
                    if(i!=a/i)
                    mp[a/i]++;
                }
            }
        }
        long long ans = 0;
        for(auto a:nums2){
            long long temp = a*k;
            if(mp.count(temp)) ans += mp[temp];
        }
        return ans;
    }
};