class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size()-1, res = 0;
        while(l<=r){
            res = max(res,min(a[l],a[r])*(r-l));
            if(a[l]>=a[r])
                r--;
            else
                l++;
        }
        return res;
    }
};