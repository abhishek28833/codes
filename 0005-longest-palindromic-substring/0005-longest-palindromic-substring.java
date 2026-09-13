class Solution {
    private int fn(String s,int i,int j,int n){
        int len = 0;
        while(i >=0 && j < n && (s.charAt(i)) == (s.charAt(j))){
            i--;
            j++;
        }
        return j-i-1;
    }

    public String longestPalindrome(String s) {
        int n = s.length(),leng = 0,idx = -1;
        for(int i=0;i<n;i++){
            int len1 = fn(s,i,i,n);
            int len2 = fn(s,i,i+1,n);
            int len = Math.max(len1,len2);
            if(len > leng){
                leng = len;
                idx = i-(len-1)/2;
            }
        }
        return s.substring(idx,idx+leng);
    }
}