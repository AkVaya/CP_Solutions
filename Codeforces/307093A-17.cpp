#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n], res = 0,curr = 0,l = 0,r = 0;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    while(r<n){
    	curr+=a[r];
    	while(curr>m && l<=r)
    		curr-=a[l++];
    	res = max(res,r-l+1);
    	r++;
    }
    cout<<res<<'\n';
    return 0;
}