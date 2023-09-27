class Solution {
public:
    int check(long long val,vector<int>& piles,int h,long long n){
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=piles[i]/val;
            if(piles[i]%val!=0){
                sum++;
            }
        }
        if(sum<=h) return 1;
        else return 0;
    }

    int bs(vector<int>& piles,long long low,long long high,int h,long long n){
        long long ans =0;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(check(mid,piles,h,n)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1; 
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        if(n==1){
            if(piles[0]%h==0) return piles[0]/h;
            else return piles[0]/h+1;
        }
        int maxi = *max_element(piles.begin(),piles.end());
        return bs(piles,1,maxi,h,n);
    }
};