class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        for(int i = 1; i < p.size(); ++i){
            if(p[i]>p[i-1])
                res+=p[i]-p[i-1];
        }
        return res;
    
    }
};