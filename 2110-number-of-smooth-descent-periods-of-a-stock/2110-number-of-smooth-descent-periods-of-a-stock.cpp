class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size();
        long long cnt = 1,ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]+1 == prices[i-1]) cnt++;
            else{
                ans += (cnt * (cnt+1))/2;
                cnt = 1;
            }
        }
        ans+=  (cnt * (cnt+1))/2;
        return ans;
    }
};