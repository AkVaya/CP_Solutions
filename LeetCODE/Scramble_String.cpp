class Solution {
public:
    bool fun(unordered_map<string, bool>&m, string s, string t){
        //cout<<s<<' '<<t<<endl;
        if(s.length()!=t.length())
            return m[s+t] = 0;
        vector<int> cnt(26, 0);
        for(int i = 0; i < s.length(); ++i){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for(auto i : cnt)
            if(i)
                return m[s+t] = false;
        if(s==t)
            return m[s+t] = 1;
        if(m.count(s+t))
            return m[s+t];
        int n = s.length();
        for(int k = 0; k < s.length()-1; ++k){
            if(fun(m, s.substr(0, k+1), t.substr(0, k+1)) && fun(m, s.substr(k+1, n-k-1), t.substr(k+1, n-k-1)))
                return m[s+t] = 1;
            if(fun(m, s.substr(0, k+1), t.substr(n-k-1, k+1)) && fun(m, s.substr(k+1, n-k-1), t.substr(0, n-k-1)))
                return m[s+t] = 1;
        }
        return m[s+t] = 0;
    }
    bool isScramble(string s, string t) {
        unordered_map<string, bool> m;
        return fun(m, s, t);
    }
};