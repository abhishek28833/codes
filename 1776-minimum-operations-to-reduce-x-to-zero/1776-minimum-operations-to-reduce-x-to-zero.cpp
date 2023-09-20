class Solution {
public:
    int bs(vector<int>& pre,int x,int cnt,int low,int high){
        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(pre[mid]+cnt == x){
                ans = mid;
                high = mid-1;
            }
            else if(pre[mid]+cnt > x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre1,pre2;
        pre1.push_back(0);
        pre2.push_back(0);
        for(int i=0;i<n;i++){
            pre1.push_back(pre1[i]+nums[i]);
            pre2.push_back(pre2[i]+nums[n-1-i]);
        }

        int ans = INT_MAX;
        for(int i=0;i<n+1;i++){
            int cnt = pre1[i];
            int temp = bs(pre2,x,cnt,0,n-i);
            if(temp!=-1){
                ans = min(ans,i+temp);
            }
        }
        if(ans!=INT_MAX)
        return ans;
        return -1;

    }
};