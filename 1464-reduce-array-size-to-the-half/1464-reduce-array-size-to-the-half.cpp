class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(auto a:arr){
            mp[a]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto a:mp){
            pq.push({a.second,a.first});
        }
        int temp = n,cnt=0;
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            cnt++;
            temp -= a.first;
            if(temp<=n/2) return cnt;
        }
        return mp.size();
    }
};