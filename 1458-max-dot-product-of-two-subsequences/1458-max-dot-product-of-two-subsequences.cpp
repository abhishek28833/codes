#include <bits/stdc++.h>
class Solution {
public:
    // int ans = INT_MIN;
    int rec(vector<int>& nums1, vector<int>& nums2, int i, int j,int n,int m,vector<vector<int>>& dp){
        if(i >= n || j >= m){
            return 0;
        } 
        
        // if(mp.count({i,j})) return mp[{i,j}];
        if(dp[i][j] != INT_MIN) return dp[i][j];

        int maxi = INT_MIN;
        maxi = max(maxi, nums1[i]*nums2[j] + rec(nums1,nums2,i+1,j+1,n,m,dp));
        maxi = max(maxi,rec(nums1,nums2,i,j+1,n,m,dp));
        maxi = max(maxi,rec(nums1,nums2,i+1,j,n,m,dp));
        return dp[i][j] = maxi;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // map<pair<int,int>,int> mp;
        vector<vector<int>> dp(n+1,vector<int> (m+1,INT_MIN));
        int ans = rec(nums1,nums2,0,0,n,m,dp);
        if(ans == 0){
            int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    maxi = max(maxi,nums1[i]*nums2[j]);
                }
            }
            return maxi;
        }
        return ans;
    }
};

// [13,-7,12,-15,-7,8,3,-7,-5,13,-15,-8,5,7,-1,3,-11,-12,2,-12]
// [-1,13,-4,-2,-13,2,-4,6,-9,13,-8,-3,-9]