class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        
        long long n = arr.size();
        long long sum = 0,sqsum = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += arr[i][j];
                sqsum += (1LL*arr[i][j]*arr[i][j]);
            }
            
        }
         
        n = n*n;
        
        long long tsum = (n*(n+1))/2;
        long long tsqsum = (n*(n+1)*((2*n)+1))/6;
        
        long long dm = sum-tsum;
        long long sdm = (sqsum-tsqsum)/dm;
        
        int d = (sdm+dm)/2;
        int m = sdm-d;
        
        return {d,m};
    }
};