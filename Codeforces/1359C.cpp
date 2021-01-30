#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 69;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        double h,c,req;
        cin>>h>>c>>req;
        if(req==h){
            cout<<1<<'\n';
            continue;
        }
        if(req<=(h+c)/2){
            cout<<2<<'\n';
            continue;
        }
        ll l = 1, r = 1e12;
        ll res = r;
        double initial = h,diff = 1e12;
        while(l<=r)
        {
            ll mid = (l+r)/2;
            double cntH = mid;
            double cntC = mid - 1;
            double val = (cntH*h + cntC*c)/(2*mid-1);
            //cout<<mid<<' '<<l<<' '<<r<<' '<<val<<' '<<diff<<endl;
            if(abs(val-req)<diff){
            //  cout<<mid<<' '<<val<<' '<<diff<<endl;
                diff = abs(val-req);
                res = 2*mid-1;
            }
            else if(abs(val-req)==diff){
                res = min(res,2*mid-1);
            }
            if(val>=req)
                l = mid+1;
            else
                r = mid-1;
        }
        cout<<res<<endl;
    }
    return 0;
}