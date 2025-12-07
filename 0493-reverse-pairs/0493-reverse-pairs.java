class MergeSort {
    public int countReversePair(int[] arr,int low, int mid, int high){
        int cnt = 0,j=mid+1;
        for(int i=low;i<=mid;i++){

            while(j<=high && arr[i] > (long)2*arr[j]){
                j++;
            } 
            cnt += j-mid-1;
        }
        return cnt;
    }
    
    public void merge(int[] arr, int low, int mid, int high) {
        int i = low;      
        int j = mid + 1;  
        int k = 0;        

        int[] temp = new int[high - low + 1];

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int p = 0; p < temp.length; p++) {
            arr[low + p] = temp[p];
        }
    }

    public int mergeSort(int[] nums, int low, int high) {
        int cnt = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            cnt += mergeSort(nums, low, mid);
            cnt += mergeSort(nums, mid + 1, high);
            cnt += countReversePair(nums, low, mid, high);
            merge(nums, low, mid, high);
        }
        return cnt;
    }
}


class Solution {
    public int reversePairs(int[] nums) {
        MergeSort obj = new MergeSort();
        return obj.mergeSort(nums, 0, nums.length - 1);
    }
}