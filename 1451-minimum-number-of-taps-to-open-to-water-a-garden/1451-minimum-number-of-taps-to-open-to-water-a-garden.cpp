class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1);
        for(int i=0;i<=n;i++) arr[i] = i;
        for(int i=0;i<=n;i++){
            arr[max(i-ranges[i],0)] = max(min(i+ranges[i],n),arr[max(i-ranges[i],0)]);
        }
        int tap = 0,save = 0,val = 0;
        for(int j=0;j<n;j++){
            if(j>save) return -1;
            val = max(val,arr[j]);
            if(save == j){
                tap++;
                save = val;
            }
        }
        if(save<n) return -1;
        return tap;
    }
};