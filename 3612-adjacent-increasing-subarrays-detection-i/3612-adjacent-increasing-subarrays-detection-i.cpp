class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(),cnt=1,temp=0;
        if(k==1 && n>1) return true;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }else{
                if(cnt >= 2*k) return true;
                if(cnt >=k && temp>0) return true;
                else if(cnt >=k && temp == 0){
                    temp++;
                    cnt = 1;
                }else{
                    cnt = 1;
                    temp = 0;
                }
            }
        }
        if(cnt >= 2*k) return true;
        if(cnt >=k && temp>0) return true;
        return false;
    }
};