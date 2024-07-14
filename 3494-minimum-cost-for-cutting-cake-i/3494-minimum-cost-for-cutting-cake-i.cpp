class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hori, vector<int>& verti) {
        sort(hori.rbegin(),hori.rend());
        sort(verti.rbegin(),verti.rend());
        int i=0,j=0,x=0,y=0;
        int ans = 0;
        while(i<m-1 && j<n-1){
            if(hori[i]>verti[j]){
                ans += (hori[i]*(y+1));
                i++;
                x++;
            }
            else{
                ans+=(verti[j]*(x+1));
                j++;
                y++;
            }
        }
        while(i<m-1){
            ans += (hori[i]*(y+1));
            i++;
        }
        while(j<n-1){
            ans+=(verti[j]*(x+1));
            j++;
        }
        return ans;
    }
};