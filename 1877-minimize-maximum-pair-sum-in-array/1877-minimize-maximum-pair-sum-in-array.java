class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length,i=0,j=n-1;
        int ans = 0;
        while(i<j){
            ans = Math.max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
}