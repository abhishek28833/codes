class Solution {
public:
    // static bool cmp(pair<char,int>& a,pair<char,int>& b){
    //     if(a.first == b.first) return a.second<=b.second;
    //     else return a.first>b.first;
    // }
    struct cmp {
    bool operator()(pair<char, int> a, pair<char, int> b) {
        if (a.first == b.first) {
            return a.second < b.second; // Max-heap for the second element
        }
        return a.first > b.first; // Min-heap for the first element
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        int n = s.size(),i=0;
        while(i<n){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            else{
                if(!pq.empty()) pq.pop();
            }
            i++;
        }
        string ans = "";
        vector<pair<int,char>> arr;
        while(!pq.empty()){
            arr.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(arr.begin(),arr.end());
        for(auto a: arr){
            ans += a.second;
        }
        return ans;
    }
};