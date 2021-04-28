class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s = countAndSay(n-1);
        string res = "";
        int cnt = 0;
        int i = 0;
        while(i<s.length()){
            char start = s[i];
            while(i<s.length() && s[i]==start){
                cnt++;
                i++;
            }
            res+=to_string(cnt) + start;
            cnt = 0;
        }
        return res;
    }
};