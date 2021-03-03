#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
ll n,l,r,res = 0;
void dfs(ll start,ll end,ll val){
	if(start>end)
		return;
	ll mid = start + (end - start)/2;
	//cout<<mid<<' '<<start<<' '<<end<<endl; 
	if(mid>=l && mid<=r && (val&1)){
		res++;
	}
	if(mid<l)
		dfs(mid+1,end,val/2);
	else if(r<mid)
		dfs(start,mid-1,val/2);
	else{
		dfs(start,mid-1,val/2);
		dfs(mid+1,end,val/2);
	}
}
ll binpow(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
int main(){
	ll x, cnt = 0;
	cin>>n>>l>>r;
	x = n;
	while(x){
		cnt++;
		x>>=1;
	}
	dfs(1,binpow(2,cnt)-1,n);
	cout<<res<<'\n';

   	return 0;
}