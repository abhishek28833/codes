class Solution {
public:
    int rec(vector<int>& nums,int i,int j){
        if(i==j) return nums[i];

        int a = 0, b=0;
        a = nums[i] - rec(nums,i+1,j);
        b = nums[j] - rec(nums,i,j-1);

        return max(a,b);


    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(),sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int temp = rec(nums,0,n-1);
        if(sum-temp > sum) return false;
        return true;

    }
};