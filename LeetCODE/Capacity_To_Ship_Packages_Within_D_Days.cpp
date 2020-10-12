class Solution {
public:
    bool check(vector<int>&weights,int capacity,int D){
        int cnt = 1,curr = 0;
        for(auto i : weights){
            if(capacity<i)
                return false;
            if(curr + i<=capacity)
                curr+=i;
            else{
                cnt++;
                curr = i;
            }
        }
        return cnt<=D;
        
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0,r = 0;
        for(auto i : weights)
            r+=i;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(weights,mid,D))
                r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    }
};