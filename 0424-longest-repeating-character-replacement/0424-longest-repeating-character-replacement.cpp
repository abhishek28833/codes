class Solution {
public:
    bool check(vector<int>& arr,int k,int total){
        for(int i=0;i<26;i++){
            int left = total-arr[i];
            if(k >= left) return true;
        }
        return false;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> arr(26,0);
        int j = 0,total=0,maxi = 0;
        for(int i=0;i<n;i++){
            int idx = s[i] - 'A';
            arr[idx]++;
            total++;
            bool c = check(arr,k,total);
            // cout<<"i: "<<i<<" j: "<<j<<" total: "<<total<<" c: "<<c<<" maxi: "<<maxi<<"\n";
            while(!c){
                int pidx = s[j]-'A';
                arr[pidx]--;
                total--;
                c = check(arr,k,total);
                j++;
                // cout<<"i: "<<i<<" j: "<<j<<" total: "<<total<<" c: "<<c<<" maxi: "<<maxi<<"\n\n";
            }
            maxi = max(maxi,i-j+1);
        }
        return maxi;
    }
};