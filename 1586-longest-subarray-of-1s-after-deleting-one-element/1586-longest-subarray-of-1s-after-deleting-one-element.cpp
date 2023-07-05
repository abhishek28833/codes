class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                ans.push_back(cnt);
                cnt =0;
            }
        }
        if(nums[n-1]!=0) ans.push_back(cnt);
        if(ans.size()==0) return 0;
        int maxi = ans[0],m=ans.size();
        for(int i=1;i<m;i++){
            int sum = ans[i-1]+ans[i];
            maxi = max(maxi,sum);
        }
        if(m==1 && ans[0]!=0) return ans[0]-1;
        return maxi;
    }
};