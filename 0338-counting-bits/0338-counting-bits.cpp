class Solution {
public:
    int rec(int n){
        if(n<=1) return n;
        int k = log2(n);
        int a =0;
        a = 1 + rec(n-(pow(2,k)));
        return a;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(rec(i));
        }
        return ans;
    }
};