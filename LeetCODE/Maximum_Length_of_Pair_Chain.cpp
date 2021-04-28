class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& a) {
        if(!a.size())
            return 0;
        sort(a.begin(), a.end(), cmp);
        int n = a.size();
        int res = 1, curr = a[0][1];
        for(int i = 1; i < n; ++i){
            if(a[i][0]>curr){
                res++;
                curr = a[i][1];
            }
        }
        return res;
    }
};