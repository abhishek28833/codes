class Solution {
public:
    long long mod = 1e9+7;

    int maximizeSquareArea(int m, int n, vector<int>& hBars, vector<int>& vBars) {
        
        hBars.push_back(m);
        vBars.push_back(n);
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        unordered_set<int> arr,brr;
        int c = hBars.size();
        int d = vBars.size();
        for(int i=0;i<c;i++){
            for(int j=0;j<i;j++){
                arr.insert(hBars[i]-hBars[j]);
            }
            arr.insert(hBars[i]-1);
        }
        arr.insert(m-1);

        int ans = 0;
        for(int i=0;i<d;i++){
            for(int j=0;j<i;j++){
                int hei = vBars[i]-vBars[j];
                if(arr.count(hei)){
                    ans = max(ans,hei);
                }
            }
            if(arr.count(vBars[i]-1)){
                ans = max(ans,vBars[i]-1);
            }
        }
        if(arr.count(n-1)){
            ans = max(ans,n-1);
        }

        return (ans == 0) ? -1: (1LL*ans*ans)%mod;

        
        return ans;
    }
};