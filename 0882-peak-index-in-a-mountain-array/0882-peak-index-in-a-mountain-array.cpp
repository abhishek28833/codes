class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ind = 0;
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid == 0 && arr[mid]<arr[mid+1]){
                ind = mid;
                low = mid+1;
            }
            else if(arr[mid]>arr[mid-1]){
                ind = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ind;
    }
};