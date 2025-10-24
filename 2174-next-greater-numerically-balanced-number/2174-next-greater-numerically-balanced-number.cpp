class Solution {
public:
    bool check(int k){
        map<int,int> mp;
        while(k){
            int rem = k%10;
            k/=10;
            mp[rem]++;
        }
        for(auto a: mp){
            if(a.first != a.second) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int k = n+1;
        while(true){
            if(check(k)) return k;
            k++;
        }
        return k;
    }
};