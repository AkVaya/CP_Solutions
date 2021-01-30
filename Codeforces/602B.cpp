#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 69;
int n, a[nax];
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    int l = 0,r = 0,res = 0;
    int cnt = 0;
    while(l<n){
        int val = a[l],curr = 1,r = l+1,ind = l;
        int mx = val,mn = val;
        while(r<n){
            mn = min(a[r],mn);
            mx = max(mx,a[r]);
            if(mx-mn>1)
                break;
            if((val!=a[r] && a[ind]!=a[r]))
                ind = r;
            if((val==a[r] && a[ind]!=val))
                ind = r;
            r++;
            curr++;
        }
        //cout<<l<<' '<<ind<<endl;
        if(ind==l)
            l = r;
        else
            l = ind;
        res = max(res,curr);
    }
    cout<<res<<'\n';
    return 0;
}