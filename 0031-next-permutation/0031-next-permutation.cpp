class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int save = -1,prev = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                int val = nums[i-1];
                int maxi= INT_MAX,ind = i-1;
                for(int j=i;j<n;j++){
                    if(nums[j]>val && nums[j]<maxi){
                        maxi = min(nums[j],maxi);
                        ind = j;
                    }
                }
                if(maxi != INT_MAX){
                    nums[i-1]=nums[ind];
                    nums[ind]=val;
                    sort(nums.begin()+i,nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(),nums.end());
    }
};