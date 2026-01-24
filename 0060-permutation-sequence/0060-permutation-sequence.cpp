class Solution {
public:
    unordered_map<int,int> mp;

    int totalFact(int n){
        int fact = 1;
        for(int i=1;i<=n;i++){
            fact *= i;
        }
        return fact;
    }

    int unVisited(int n,int x){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!mp.count(i)){
                cnt++;
                if(cnt == x || x==0) return i;
            }
        }
        return 0;
    }

    string getPermutation(int n, int k) {
        string ans = "";

        int cn = n;
        int ck = k;
        while(cn){
            int fact = totalFact(cn);
            int value = fact/cn ;
            int x;
            if(ck%value == 0) x = unVisited(n,(ck/value));
            else x = unVisited(n,(ck/value)+1);

            

            cout<<"cn: "<<cn<<" x: "<<x<<" ck: "<<ck<<" value: "<<value<<"\n";

            // ck = (ck%value == 0)? ck/value : (ck/value);
            

            mp[x]++;
            ans += to_string(x);
            cn--;
            // ck = (ck%value != 0)?ck-value:min(ck,cn);
            int y = value * (ck/value);

            if(y < ck){
                ck = ck-y;
            }else{
                ck = value;
            }

            
        }
        return ans;
    }
};