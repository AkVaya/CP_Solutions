class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int>cnt(26, 0);
        priority_queue<pair<int, int> > pq;
        for(auto i : s)
            cnt[i-'a']++;
        int mx = 0, val;
        for(int i = 0; i < 26; ++i){
            if(cnt[i]>(n+1)/2)
                return "";
            if(cnt[i])
                pq.push({cnt[i], i});
        }
        string res;
        while(res.size() < n){
            pair<int, int> fir = pq.top();
            pq.pop();
            pair<int, int> sec = pq.top();
            pq.pop();
            if(fir.first>0){
                res+=(fir.second + 'a');
                fir.first--;
                pq.push(fir);
            }
            if(sec.first>0){
                res+=(sec.second + 'a');
                sec.first--;
                pq.push(sec);
            }
        }
        return res;
    }
};