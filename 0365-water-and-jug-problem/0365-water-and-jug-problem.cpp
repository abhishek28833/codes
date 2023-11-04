class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int tar) {
        if(tar > jug1+jug2) return false;
        if(jug1%2==0 && jug2%2==0 && tar%2==1) return false;
        if(jug1==0 && jug2!=tar) return false;
        if(jug2==0 && jug1!=tar) return false;
        int g = __gcd(jug1,jug2);
        if(g==1) return true;
        if(tar%g==0) return true;
        return false;
        
    }
};