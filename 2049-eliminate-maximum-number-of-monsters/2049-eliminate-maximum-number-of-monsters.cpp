class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = speed.size();
        vector<double> time(n,0);
        for(int i=0;i<n;i++){
            time[i] = double(dist[i])/double(speed[i]);
        }
        int cnt =0;
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            if(time[i]>i) cnt++;
            else break;
        }
        return cnt;
    }
};