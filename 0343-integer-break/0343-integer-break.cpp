class Solution {
public:
    int rec(int n){
        if(n<=3) return n;
        int a = 0;
        if(n-3>1) a = 3*rec(n-3);
        else a = 2*rec(n-2);
        return a;
    }

    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        return rec(n);
    }
};