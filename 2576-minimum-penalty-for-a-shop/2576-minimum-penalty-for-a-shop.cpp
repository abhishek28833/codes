class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int yes = 0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') yes++;
        }
        int mini = yes,ans = 0,no=0,cnt = 0,k=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                cnt++;
            }
            else{
                int len = yes - cnt;
                int final = len + no;
                if(final<mini){
                    mini = final;
                    k = i;
                }
                no++;
            }
        }
        if(no < mini){
            k = n;
        }
        return k;
        
    }
};