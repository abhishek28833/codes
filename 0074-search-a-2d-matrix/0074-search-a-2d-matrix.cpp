class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int p = 0;
        if(m==1 && n==1 && matrix[0][0]== target)
        return 1;
        else if(m==1 && n==1)
        return 0;
        cout<<p;
        for(int i = 1;i<n;i++){
            if(target > matrix[i-1][m-1] && target <= matrix[i][m-1]){
                p=i;
                break;
            }
            
        }
        int start = 0;
        int end = m-1;
        
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[p][mid] == target)
            return 1;
            else if(target < matrix[p][mid]){
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return 0;
    }
};