#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69;
ll st[nax][18],lg[nax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		st[i][0] = a[i];
	}
	lg[1] = 0;
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i/2]+1;
	for (int j = 1; j <= 17; ++j)
		for (int i = 0; i + (1LL<<j) <= n; ++i)
			st[i][j] = min(st[i][j-1],st[i + (1LL<<(j-1))][j-1]);
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		int j = lg[r-l+1];
		cout<<min(st[l][j],st[r-(1LL<<j)+1][j])<<'\n'; 
	}
	return 0;
}