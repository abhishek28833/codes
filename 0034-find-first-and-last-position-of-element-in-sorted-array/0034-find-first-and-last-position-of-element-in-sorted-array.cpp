class Solution {
public:
    int binarysearchleft(vector<int> nums,int target){
        int s =0,e = nums.size();
        int ind=-1;
        int mid =0;
        while(s<e){
            mid = (s+e)/2;
            if(nums[mid]==target){
                ind = mid;
                e = mid;
            }
            else if(nums[mid]>target)
            e = mid;
            else
            s = mid+1;
        }
        return ind;
    }

    int binarysearchright(vector<int> nums,int target){
        int s =0,e = nums.size();
        int ind=-1;
        int mid =0;
        while(s<e){
            mid = (s+e)/2;
            if(nums[mid]==target){
                ind = mid;
                s = mid+1;
            }
            else if(nums[mid]>target)
            e = mid;
            else
            s = mid+1;
        }
        return ind;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> a(2,-1);
        a[0]=binarysearchleft(nums,target);
        a[1]=binarysearchright(nums,target);
        return a;
        
    }
};