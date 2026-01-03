class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,priority_queue<int>> mp;
        for(int i=0;i<n;i++){
            int rem = nums[i]%3;
            mp[rem].push(nums[i]);
        }

        int a =0,b=0,c=0;
        if(mp[0].size() >= 3){
            a += mp[0].top();
            b = a;
            c++;
            mp[0].pop();
            a += mp[0].top();
            mp[0].pop();
            a += mp[0].top();
        }else if(mp[0].size() > 0){
            b = mp[0].top();
            c++;
        }

        // cout<<b<<" ";

        int ans = 0;
        ans = max(ans,a);
        a = 0;

        if(mp[1].size() >= 3){
            a += mp[1].top();
            b += a;
            c++;
            mp[1].pop();
            a += mp[1].top();
            mp[1].pop();
            a += mp[1].top();
        }else if(mp[1].size() > 0){
            b += mp[1].top();
            c++;
        }

        ans = max(ans,a);
        a = 0;

        // cout<<b<<" ";

        if(mp[2].size() >= 3){
            a += mp[2].top();
            b += a;
            c++;
            mp[2].pop();
            a += mp[2].top();
            mp[2].pop();
            a += mp[2].top();
        }else if(mp[2].size() > 0){
            b += mp[2].top();
            c++;
        }

        ans = max(ans,a);

        // cout<<b<<" ";

        if(c == 3) ans = max(ans,b);
        return ans;
    }
};