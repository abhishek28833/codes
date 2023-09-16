class Solution {
public:
    int d1[4] = {0,0,-1,1};
    int d2[4] = {-1,1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dis[0][0] = 0;
        while(!pq.empty()){
            auto val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int row = x + d1[i];
                int col = y + d2[i];
                if(row>=0 && col>=0 && row<n && col<m){
                    int diff = abs(heights[x][y]-heights[row][col]);
                    int save = max(val,diff);
                    if(save < dis[row][col]){
                        dis[row][col] = save;
                        pq.push({save,{row,col}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};