class Solution {
public:
    char q = 'Q';
    char d = '.';
    vector<vector<string>> ans;
    string createBoard(int n){
        string s = "";
        for(int i=0;i<n;i++){
            s += d;
        }
        return s;
    }

    bool checkRow(vector<string>& arr,int n,int row,int col){
    
        for(int i=0;i<n;i++){
            if(i == row) continue;
            if(arr[i][col] == q) return false;
        }
        return true;
    }

    bool checkCol(vector<string>& arr,int n,int row,int col){
        for(int j=0;j<n;j++){
            if(j == col) continue;
            if(arr[row][j] == q) return false;
        }
        return true;
    }

    bool diaonalCheck(vector<string>& arr,int n,int row,int col){
        int c = col-1,r = row-1;
        while(c>=0 && r>=0){
            if(arr[r][c] == q) return false;
            c--;
            r--;
        }

        c = col+1,r = row+1;
        while(c<n && r<n){
            if(arr[r][c] == q) return false;
            c++;
            r++;
        }

        c = col+1,r = row-1;
        while(c<n && r>=0){
            if(arr[r][c] == q) return false;
            c++;
            r--;
        }

        c = col-1,r=row+1;
        while(c>=0 && r<n){
            if(arr[r][c] == q) return false;
            r++;
            c--;
        }
        return true;
    }

    bool fullCheck(vector<string>& arr,int n,int i,int j){
        if(!checkRow(arr,n,i,j) || !checkCol(arr,n,i,j) || !diaonalCheck(arr,n,i,j)) return false;
        return true;
    }

    void rec(vector<string>& arr,int n,int row){
        if(row == n){
            ans.push_back(arr);
            return;
        }
        for(int j=0;j<n;j++){
            if(arr[row][j]==d && fullCheck(arr,n,row,j)){
                arr[row][j] = q;
                rec(arr,n,row+1);
                arr[row][j] = d;
            }
        }
        return;

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> arr;
        string str = createBoard(n);
        for(int i=0;i<n;i++){
            arr.push_back(str);
        }
        rec(arr,n,0);
        return ans;
    }
};