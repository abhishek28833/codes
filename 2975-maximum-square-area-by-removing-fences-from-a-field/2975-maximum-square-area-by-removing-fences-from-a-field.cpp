class Solution {
public:
    long long mod = 1e9+7;

    int maximizeSquareArea(int m, int n, vector<int>& hBars, vector<int>& vBars) {
        vector<int> arr,brr;
        hBars.push_back(m);
        vBars.push_back(n);
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int c = hBars.size();
        int d = vBars.size();
        for(int i=0;i<c;i++){
            for(int j=0;j<i;j++){
                arr.push_back(hBars[i]-hBars[j]);
            }
            arr.push_back(hBars[i]-1);
        }
        arr.push_back(m-1);


        for(int i=0;i<d;i++){
            for(int j=0;j<i;j++){
                brr.push_back(vBars[i]-vBars[j]);
            }
            brr.push_back(vBars[i]-1);
        }
        brr.push_back(n-1);


        int ans = -1;
        int a = arr.size(),b = brr.size();
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        int i=0,j=0;
        while(i<a && j<b){
            if(arr[i] == brr[j]){
                ans = max(ans,arr[i]);
                i++;j++;
            }else if(arr[i] > brr[j]) j++;
            else i++;
        }
        return (ans == -1) ? -1 : (1LL* ans * ans)%mod;
    }
};