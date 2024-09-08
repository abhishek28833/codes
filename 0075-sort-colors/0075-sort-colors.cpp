class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st =0,end = nums.size()-1,i=0;
        while(i<=end){
            if(nums[i]==2){
                swap(nums[i],nums[end]);
                end--;
            }
            else if(nums[i]==0){
                swap(nums[i],nums[st]);
                if(i==st) i++;
                st++;
            }
            else{
                i++;
            }
        }
    }
};