class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber < 27){
            string a ="";
            a+= char(64+columnNumber);
            return a;
        }
        int temp = columnNumber%26;
        string b = "";
        if(temp!=0){
            b+=char(64+temp);
            return convertToTitle(columnNumber/26)+b;
        }
        
        else{
            b+='Z';
            return convertToTitle(columnNumber/26-1)+b;
        }
        
    }
};