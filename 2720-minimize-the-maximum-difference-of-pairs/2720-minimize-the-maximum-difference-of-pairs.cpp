class Solution {
public:
    int check(vector<int>& nums,int mid,int p,int n){
        int cnt = 0;
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i] <= mid){
                cnt++;
                i+=2;
            }
            else{
                i++;
            }
        }
        if(cnt>=p) return 1;
        return 0;
    }


    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0,high = nums[n-1]-nums[0],ans =0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(check(nums,mid,p,n)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            

        }
        return ans;
        
    }
};