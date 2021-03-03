#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n],curr = 0, res = 0, l = 0;
    for (int i = 0; i < n; ++i)
	    cin>>a[i];
	for (int i = 0; i < n; ++i)
	{
		curr+=a[i];
		if(curr>m){
			while(l<=i && curr>m){
				curr-=a[l++];
			}
		}
		if(curr<=m)
			res = max(res,curr);
	}
	cout<<res<<'\n';
   	return 0;
}