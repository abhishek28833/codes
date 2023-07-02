class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = 0,mini = 0,n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mini]) mini = i;
            if(nums[i]>nums[maxi]) maxi = i;
        }

        int a=0,b=0,c=0;
        a = max(mini,maxi)+1;
        b = n - min(mini,maxi);
        c = min(mini,maxi) +1 + n - max(mini,maxi);
        return min(a,min(b,c));

    }
};