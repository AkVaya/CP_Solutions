class Solution {
public:
    void fun(string s, vector<int> &lps){
        int i = 1, j = 0;
        lps[0] = 0;
        while(i<s.size()){
            if(s[i]==s[j])
                lps[i++] = ++j;
            else if(j)
                j = lps[j-1];
            else{
                lps[j] = 0;
                i++;
            }
        }
    }
    int strStr(string s, string t) {
        int n = s.length(), m = t.length();
        if(!m)
            return 0;
        vector<int> lps(m, 0);
        fun(t, lps);
        int i = 0, j = 0;
        while(i<n){
            if(s[i]==t[j]){
                j++;
                i++;
            }
            if(j==m)
                return i-m;
            if(i<n && s[i]!=t[j]){
                if(j)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};