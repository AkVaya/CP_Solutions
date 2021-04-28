class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        if(!a.size())
            return false;
        int n = a.size(), m = a[0].size();
        int l = 0, r = n - 1;
        while(l<=r){
            int mid = (l + r)/2;
            if(a[mid][0]==target)
                return true;
            else if(a[mid][0]<target)
                l = mid + 1;
            else r = mid - 1;
        }
        int row = l - 1;
        //cout<<row<<endl;
        if(row==-1)
            return false;
        int ind = lower_bound(a[row].begin(), a[row].end(), target) - a[row].begin();
        if(ind<m && a[row][ind]==target)
            return true;
        return false;
    }
};