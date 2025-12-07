class MergeSort {
    
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

    public void mergeSort(int[] nums, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }
}

class Solution {
    public int[] sortArray(int[] nums) {
        MergeSort obj = new MergeSort();
        obj.mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
}
