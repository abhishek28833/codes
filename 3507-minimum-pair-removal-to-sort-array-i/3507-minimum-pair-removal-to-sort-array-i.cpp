class Solution {
public:
    int getMinPos(vector<int>& v){
        int n = v.size(),mini= INT_MAX,pos=0;
        for(int i=0;i<n-1;i++){
            if(v[i]+v[i+1] < mini){
                mini = v[i]+v[i+1];
                pos = i;
            }
        }
        return pos;
    }


    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!is_sorted(nums.begin(),nums.end())){
            int pos = getMinPos(nums);
            nums[pos] = nums[pos] + nums[pos+1];
            nums.erase(nums.begin()+pos+1);
            cnt++;
        }
        return cnt;
    }
};