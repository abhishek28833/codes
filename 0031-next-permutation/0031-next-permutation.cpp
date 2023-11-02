class Solution {
public:
    int fn(vector<int>& nums,int i,int n,int val){
        sort(nums.begin()+i,nums.end());
        for(int j=i;j<n;j++){
            if(nums[j]>val) return j;
        }
        return 0;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                int a = fn(nums,i-1,n,nums[i-1]);
                swap(nums[i-1],nums[a]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());

    }
};