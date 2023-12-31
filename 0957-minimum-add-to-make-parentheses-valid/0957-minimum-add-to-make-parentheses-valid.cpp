class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        int cnt =0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(s[i]);
            else if(!st.empty()) st.pop();
            else cnt++;
        }
        while(!st.empty()){
            cnt++;
            st.pop();

        }
        return cnt;
    }
};