class Solution {
public:
    int la(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            int a = heights[i];
            for(int j=i;j<n;j++){
                a = min(a,heights[j]);
                maxi = max(maxi,a*(j-i+1));
            }
        }
        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int> (m,0));

        for(int j=0;j<m;j++){
            arr[0][j] = matrix[0][j]-'0';
            for(int i=1;i<n;i++){
                if(matrix[i][j]=='1')
                arr[i][j] = arr[i-1][j] + (matrix[i][j]-'0');
            }
        }


        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,la(arr[i]));
        }
        return maxi;

    }
};