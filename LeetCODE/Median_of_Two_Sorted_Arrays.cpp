class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())
            return findMedianSortedArrays(b,a);
        int n = a.size(), m = b.size();
        int l = 0, r = n, res = 0 ;
        while(l<=r){
            int fir = (l + r)/2;
            int sec = (n + m + 1)/2 - fir;
            
            //cout<<fir<<' '<<sec<<endl;
            int lf1 = (fir==0 ? INT_MIN : a[fir-1]);
            int rt1 = (fir==n ? INT_MAX : a[fir]);
            
            int lf2 = (sec==0 ? INT_MIN : b[sec-1]);
            int rt2 = (sec==m ? INT_MAX : b[sec]);
            //cout<<lf1<<' '<<rt1<<' '<<lf2<<' '<<rt2<<endl;
            if(lf1<=rt2 && lf2<=rt1){
                if((n+m)%2)
                    return max(lf1, lf2);
                long double x = max(lf1, lf2) + min(rt2, rt1);
                return x/2.0;
            }
            else if(lf1>rt2){
                r = fir - 1;
            }
            else{
                l = fir + 1;
            }
        }
        return 0;
    }
};