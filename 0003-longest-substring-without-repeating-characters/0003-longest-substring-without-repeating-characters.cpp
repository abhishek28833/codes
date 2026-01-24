#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int j=0,ans =0;
        for(int i=0;i<n;i++){
            while(mp.count(s[i])){
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
                j++;
            }
            mp[s[i]]++;
            ans = max(ans,(int)mp.size());
            // cout<<"i: "<<s[i]<<" ans: "<<ans<<"\n";
        }
        return ans;
    }
};