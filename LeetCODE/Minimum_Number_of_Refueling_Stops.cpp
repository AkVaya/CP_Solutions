class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int res = 0,ind = 0;
        while(startFuel< target){
            while(ind<stations.size() && startFuel>=stations[ind][0])
                pq.push(stations[ind++][1]);
            if(pq.empty())
                return -1;
            startFuel += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};