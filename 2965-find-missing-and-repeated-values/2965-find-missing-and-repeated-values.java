class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        long n = grid.length;
        long arrSum = 0;
        long arrSquareSum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arrSum += grid[i][j];
                arrSquareSum += (grid[i][j] * grid[i][j]);
            }
        }
        

        n = n*n;
        long totalSum = (n*(n+1))/2;
        long totalSquareSum = (n*(n+1)*(2*n+1))/6;

        long a_b = totalSum - arrSum;
        long a2_b2 = totalSquareSum - arrSquareSum;

        long aSumb = a2_b2/a_b;

        int a = (int)(aSumb + a_b)/2;
        int b = (int) aSumb - a;

        int[] ans = {b,a};
        return ans;
    }
}