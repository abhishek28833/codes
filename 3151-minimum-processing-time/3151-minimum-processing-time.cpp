class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        int n = processorTime.size();
        int j=4*n-1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,tasks[j]+processorTime[i]);
            j-=4;
        }
        return maxi;
    }
};