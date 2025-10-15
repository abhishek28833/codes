class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(),cnt=1,temp=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }else{
                if(cnt >= 2*k || (cnt >=k && temp>0)) return true;
                else if(cnt >=k && temp == 0) temp++;
                else temp = 0;
                cnt = 1;
            }
        }
        if(cnt >= 2*k || (cnt >=k && temp>0)) return true;
        return false;
    }
};