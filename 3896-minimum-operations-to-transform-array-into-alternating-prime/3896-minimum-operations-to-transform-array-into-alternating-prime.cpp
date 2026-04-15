class Solution {
public:
    vector<int> prime;

    int checkPrime(int n){
        if(n == 2) return 1;
        if(n <= 1 || n%2==0) return 0;
        for(int i=3;i*i<=n;i+=2){
            if(n%i == 0) return 0;
        }
        return 1;
    }

    void primeset(){
        for(int i=0;i<1e5+5;i++){
            if(checkPrime(i)){
                // cout<<i<<" ";
                prime.push_back(i);
            }
            
        }
    }

    int justGreaterPrime(int n){
        int low = 0,high = prime.size(),ans = 1e5+3;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(prime[mid] >= n){
                ans = min(ans,prime[mid]);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;

    }

    int minOperations(vector<int>& nums) {
        primeset();
        int n = nums.size(),ans=0;
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                if(!checkPrime(nums[i]))
                ans += justGreaterPrime(nums[i])-nums[i];
            }else{
                if(nums[i] == 2) ans += 2;
                else if(checkPrime(nums[i])) ans++;
            }
            
        }
        return ans;
    }
};