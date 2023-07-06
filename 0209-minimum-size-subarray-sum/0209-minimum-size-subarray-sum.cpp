class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        int i=0,j=0,sum=0;
        while(i<n && j<n){
            sum+=nums[i];
            while(j<=i && sum>=target){
                mini = min(mini,i-j+1);
                sum-=nums[j];
                j++;
                
            }
            i++;
        }
        while(j<n && sum>=target){
            mini = min(mini,i-j+1);
            sum-=nums[j];
            j++;
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};