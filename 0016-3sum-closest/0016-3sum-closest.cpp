class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(),ans = INT_MAX,mini = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int val = (nums[i]+nums[j]+nums[k]);
                if(val-target > 0){
                    k--;
                }else if(val-target < 0) j++;
                else return val;
                if(abs(val-target) < mini){
                    mini = abs(val-target);
                    ans = val;
                }
            }
        }
        return ans;
    }
};