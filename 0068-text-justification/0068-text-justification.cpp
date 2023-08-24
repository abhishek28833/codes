class Solution {
public:
    string add(string s,int k,int len){
        // cout<<s<<"\n";
        // cout<<k<<" "<<len<<"\n";
        int store = k/len;
        string str = s;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                string temp(store,' ');
                s.insert(i+1,temp);
                k-=store;
            }
        }
        
        if(k!=0){
            vector<int> vii;
            for(int i=1;i<n;i++){
                if(s[i-1]!=' ' && s[i]==' '){
                    vii.push_back(i);
                    k--;
                    if(k==0) break;
                }
            }
            int si = vii.size();
            for(int i=si-1;i>=0;i--){
                s.insert(vii[i]," ");
            }
            // cout<<s<<"\n\n";
            return s;
        }
        else{
            // cout<<s<<"\n\n";
            return s;
        } 
        

        // for(int i=n)

    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i=0;
        while(i<n){
            string s = "";
            int len = -1;
            while(s.length() < maxWidth ){
                if(s.length()==0){
                    s += words[i];
                    i++;
                    len++;
                }
                else if(i<n && s.length()+words[i].length()+1<=maxWidth){
                    s+= ' ';
                    s += words[i];
                    i++;
                    len++;
                }
                else{
                    int k = maxWidth-s.length();
                    if(len!=0 && i!=n)
                    s = add(s,k,len);
                    else{
                        string temp(k,' ');
                        s += temp;
                    }
                    // cout<<s.length()<<" ";
                }
            }
            ans.push_back(s);
        }
        return ans;
        // vector<string> final = {"This    is     a","example  of text","justification.  "};
        // return final;

    }
};