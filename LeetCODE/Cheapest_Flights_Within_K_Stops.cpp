class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& e, int s, int d, int k) {
        vector<vector<pair<int,int> > > v(n);
        for(auto i : e){
            v[i[0]].push_back({i[1], i[2]});
        }
        typedef tuple<int, int, int> t;
        priority_queue<t, vector<t>, greater<t> >pq;
        pq.push({0, s, k+1});
        while(pq.size()){
            int dist = get<0>(pq.top());
            int curr = get<1>(pq.top());
            int steps = get<2>(pq.top());
            pq.pop();
            if(steps<0)
                continue;
            if(curr==d)
                return dist;
            for(auto i : v[curr]){
                pq.push({dist+i.second, i.first, steps-1});
            }
        }
        return-1;
        
    }
};