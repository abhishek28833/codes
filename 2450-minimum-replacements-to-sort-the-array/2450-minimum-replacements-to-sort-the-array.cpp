class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long n = nums.size();
        long long val = nums[n-1];
        long long cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>val){
                long long a = nums[i]/val;
                long long b = nums[i]%val;
                if(b!=0){
                    a++;
                }
                val = nums[i]/a;
                cnt+=a-1;
                
            }
            else{
                val = nums[i];
            }
        }
        return cnt;
    }
};