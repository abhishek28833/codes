class Solution {
public:
    #define ll long long 
    int count_digit(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    long long sumDigitDifferences(vector<int>& nums) {
        ll n = nums.size();
        map<int,vector<int>> mp;
        ll cnt = count_digit(nums[0]);
        for(int i=0;i<cnt;i++){
            for(int j=0;j<n;j++){
                int tmp = nums[j]%10;
                nums[j]/=10;
                mp[i].push_back(tmp);
            }
        }

        // print(mp);

        ll ans = 0;
        for(auto& a:mp){
            ll val = 0,prev = 0;
            sort(a.second.begin(),a.second.end());
            for(int i=1;i<n;i++){
                // cout<<a.second[i-1]<<" "<<a.second[i]<<"\n";
                if(a.second[i]!=a.second[i-1]){
                    val += i;
                    prev = i;
                }
                else val+= prev;
                // cout<<val<<"\n";
            }
            // cout<<"\n";
            // cout<<a.first<<"-> "<<val<<"\n";
            ans += val;
        }
        return ans;
    }
};