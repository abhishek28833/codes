class Solution {
public:

    // it returns the number of element less than or eqal to the val , cnt is done because of the similar element in both of the array.
    int bs2(vector<int>& nums,int n,int val,int cnt){
        int ans = 0;
        int low = 0,high = n-1;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] > val) high = mid-1;
            else if(nums[mid] < val){
                ans = mid+1;
                low = mid+1;
            }else if(mid+1 == cnt) return mid+1;
            else if(mid+1 > cnt) high = mid-1;
            
            else low = mid+1;
            
        }
        return ans;
    }

    // it return the number if it is from the nums 1 .
    int bs1(vector<int>& nums1, vector<int>& nums2,int idx,int n, int  m){
        int low = 0,high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            int cnt = mid+bs2(nums2,m,nums1[mid],idx-mid);

            if(cnt == idx) return nums1[mid];
            else if(cnt > idx){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return INT_MIN;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();

        int sm = n+m;

        if(sm%2 == 1){
            int idx = sm/2;
            double check = bs1(nums1,nums2,idx,n,m);
            if(check == INT_MIN){
                check = bs1(nums2,nums1,idx,m,n);
            }
            // cout<<"check: "<<check<<"\n";
            return check;
        }else{
            int idx1 = sm/2;
            double check1 = bs1(nums1,nums2,idx1,n,m);
            if(check1 == INT_MIN){
                check1 = bs1(nums2,nums1,idx1,m,n);
            }

            int idx2 = idx1-1;
            double check2 = bs1(nums1,nums2,idx2,n,m);
            if(check2 == INT_MIN){
                check2 = bs1(nums2,nums1,idx2,m,n);
            }

            // cout<<"check1: "<<check1<<" check2: "<<check2<<"\n";

            return (check1+check2)/2;

        }
    }
};