class Solution {
public:
    string longestCommonPrefix(vector<string>& st) {
        if(st.size()==1)
            return st[0];
        string res;
        int i = 0;
        while(1){
            bool check = true;
            if(i>=st[0].length())
                break;
            char x = st[0][i];
            for(auto s : st){
                if(i>=s.length() || s[i]!=x){
                    check = false;
                    break;
                }
            }
            i++;
            if(check)
                res+=x;
            else
                break;
        }
        return res;
    }
};