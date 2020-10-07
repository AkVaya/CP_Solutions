class Solution {
public:
    #define pb push_back
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string> > m;
        for(auto i : strs){
            vector<int> cnt(26,0);
            for(auto j : i)
                cnt[j-'a']++;
            m[cnt].pb(i);
        }
        vector<vector<string> > res;
        int ind = 0;
        for(auto i : m)
            res.pb(i.second);
        return res;
    }
};