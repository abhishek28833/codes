class Solution {
public:
    int countLaser(string row){
        int cnt = 0;
        for(auto a: row){
            if(a == '1') cnt++;
        }
        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        int prev = countLaser(bank[0]);
        int ans = 0,n = bank.size();
        for(int i=1;i<n;i++){
            int newCount = countLaser(bank[i]);
            if(newCount > 0){
                ans += (prev * newCount);
                prev = newCount;
            }   
        }
        return ans;
    }
};