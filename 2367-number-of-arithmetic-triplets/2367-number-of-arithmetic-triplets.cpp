   class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size(),cnt = 0;
        for(int i=0;i<n-1;i++){
            int j = i+1,k=n-1;
            while(j<k){
                if(nums[j] - nums[i] == diff){
                    if(nums[k] - nums[j] == diff){
                        cnt++;j++;k--;
                    }else if(nums[k] - nums[j] > diff) k--;
                    else j++;
                }else if(nums[j] - nums[i] < diff) j++;
                else break;
            }
        }
        return cnt;
    }
};