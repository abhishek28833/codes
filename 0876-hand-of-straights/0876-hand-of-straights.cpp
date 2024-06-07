class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;
        for(auto a:hand){
            mp[a]++;
        }
        vector<pair<int,int>> arr;
        for(auto a:mp){
            arr.push_back({a.first,a.second});
        }

        int si = arr.size();
        // cout<<si;
        for(int i=0;i<si;i++){
            if(arr[i].second==0) continue;
            int val = arr[i].second;
            int key = arr[i].first;
            int x = groupSize-1;
            int j = i+1;
            while(j<si && x>0){
                if(arr[j].second < val || arr[j].first != key+1) return false;
                else arr[j].second-= val;
                j++;
                key++;
                x--;
            }
            if(x>0) return false;
        }
        return true;
    }
};