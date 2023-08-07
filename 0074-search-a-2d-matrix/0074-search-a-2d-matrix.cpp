class Solution {
public:
    int binary_search(vector<vector<int>>& matrix,int target,int i,int low,int high){
        if(low>high) return 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[i][mid]==target) return 1;
            if(matrix[i][mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return 0;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target && binary_search(matrix,target,mid,0,m-1)){
                return true;
            }
            if(target>matrix[mid][m-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};