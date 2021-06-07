#include<bits/stdc++.h> 
using namespace std; 
const int nax = 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, p;
    cin>>n>>p;
    ll a[2*n], sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        a[n+i] = a[i];
        sum+=a[i];
    }
    ll cnt = (p + sum - 1) / sum;
    p = p - sum*(cnt-1);
    ll mx = 1e18, l = 0, curr = 0, start ;
    for (int r = 0; r < 2*n; ++r)
    {
        curr+=a[r];
        while(l<r && l<n && curr-a[l]>=p)
            curr-=a[l++];
        if(curr>=p && r-l+1<mx && l<n){
            mx = r-l+1;
            start = l+1;
        }
        if(curr>=p){
            curr-=a[l];
            l++;
        }
        //cout<<l<<' '<<r<<endl;
    }
    mx = mx + (cnt-1)*n;
    cout<<start<<' '<<mx<<'\n';

    return 0;
}