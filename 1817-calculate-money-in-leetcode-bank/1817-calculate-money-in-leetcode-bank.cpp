class Solution {
public:
    int totalMoney(int n) {
        int flag = n%7 , prevWeeks = n/7;;
        return ((prevWeeks*((2*28) + ((prevWeeks-1)*7)))/2) + (flag * ((2*(prevWeeks+1)) + (flag-1)))/2;
    }
};