class Solution {
public:
    int trap(vector<int>& a) {
        if(!a.size())
            return 0;
        int last = a[0],res = 0;
        int mx = a[0];
        for(int i = 1; i < a.size(); ++i){
            if(a[i]>last){
                last = a[i];
            }
            else{
                res+=(last-a[i]);
            }
            mx = max(a[i],mx);
        }
        cout<<res<<endl;
        int ind = a.size()-1;
        last = a[ind];
        while(ind>=0 && last<mx){
            if(a[ind]>=last)
                res -= (mx-a[ind]);
            else res -= mx-last;
            last = max(last,a[ind--]);
        }
        return res;
    }
};