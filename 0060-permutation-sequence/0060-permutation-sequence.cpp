class Solution {
public:
    unordered_map<int,int> vis;

    int totalFact(int n){
        if(n==1) return 1;
        return n*totalFact(n-1);
    }

    int unVisited(int n,int x){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!vis.count(i)){
                cnt++;
                if(cnt == x || x==0) return i;
            }
        }
        return 0;
    }

    string rec(int cn, int ck,int n){
        if(cn == 0) return "";
        int fact = totalFact(cn), value = fact/cn ,x;

        if(ck%value == 0) x = unVisited(n,(ck/value));
        else x = unVisited(n,(ck/value)+1);

        vis[x]++;
        
        int y = value * (ck/value);

        if(y < ck) ck = ck-y;
        else ck = value;
        
        return to_string(x) + rec(cn-1,ck,n);
    }

    string getPermutation(int n, int k) {
        return rec(n,k,n);
    }
};