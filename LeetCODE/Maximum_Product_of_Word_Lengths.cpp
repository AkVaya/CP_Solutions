class Solution {
public:
    int maxProduct(vector<string>& s) {
        int n = s.size();
        vector<int> val(n,0);
        for(int i = 0; i < n; ++i)
            for(auto j : s[i])
                val[i] |= (1<<(j-'a'));
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                if((val[i] & val[j]) == 0)
                    res = max(res,(int)(s[i].length()*s[j].length()));
        return res;
    }
};