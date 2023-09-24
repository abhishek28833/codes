class Solution {
public:
    double rec(double qua,map<pair<int,int>,double>& mp,int i,int j){
        if(i==0){
            mp[{i,j}] = qua;
            if(mp[{i,j}] > 1){
                double val = mp[{i,j}]-1;
                return double(val)/double(2);
            }
            else return 0.0;
        } 

        if(mp.count({i,j})){
            if(mp[{i,j}]<=1) return 0;
            else{
                double val = mp[{i,j}]-1;
                return val/double(2);
            }
        }
        

        if(j==0){
            mp[{i,j}] = rec(qua,mp,i-1,0);
            if(mp[{i,j}] >1){
                double val = mp[{i,j}]-1;
                return double(val)/double(2);
            }
            else return 0;
        }
        else if(i==j){
            mp[{i,j}] = rec(qua,mp,i-1,j-1);
            if(mp[{i,j}] >1){
                double val = mp[{i,j}]-1;
                return double(val)/double(2);
            }
            else return 0;
        }
        else{
            mp[{i,j}] = rec(qua,mp,i-1,j-1) + rec(qua,mp,i-1,j);
            if(mp[{i,j}] >1){
                double val = mp[{i,j}]-1;
                return double(val)/double(2);
            }
            else return 0;
        }
        return 0;

        
    
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        map<pair<int,int>,double> mp;
        rec(poured,mp,query_row,query_glass);
        if(mp[{query_row,query_glass}]>1) return 1.0;
        else return mp[{query_row,query_glass}];
    }
};