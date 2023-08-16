class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vis(n,0);
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int j = 0;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push({nums[i],i});
                if(pq.size()==k){
                    ans.push_back(pq.top().first);
                }
            }
            else{
                vis[j++] = 1;
                pq.push({nums[i],i});
                auto a = pq.top();
                while(vis[a.second]==1){
                    pq.pop();
                    a = pq.top();
                }
                ans.push_back(a.first);
                
            }
        }
        if(ans.size()==0){
            auto a = pq.top();
            ans.push_back(a.first);
        }
        return ans;
    }
};