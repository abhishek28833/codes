class Fancy {
public:
    vector<pair<long long,long long>> arr;
    long long add = 0,mul = 1;
    long long mod = 1e9+7;
    Fancy() {
        
    }

    long long modExp(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;

        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    
    void append(int val) {
        int x = (val-add)%mod + mod;
        arr.push_back({x,mul});
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
        mul = (mul * m)%mod;
        add = (add * m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx < arr.size()){
            // cout<<"nume: "<<arr[idx].first<<" deno: "<<arr[idx].second<<" add: "<<add<<" mul: "<<mul<<"\n";
            return ((arr[idx].first * mul) % mod * modExp(arr[idx].second, mod-2, mod) % mod + add) % mod;
        }
        
        return -1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */