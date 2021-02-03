#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 69;
const int M = 1e9 + 7;
using ll = long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,res = 0;
	cin>>n;
	ll a[n],temp[2*n],ind = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(i%2)
			temp[ind++] = a[i];
	}
	for (int i = 0; i < n; i+=2)
		temp[ind++] = a[i];
	for (int i = n; i < 2*n; ++i)
		temp[i] = temp[i-n];
	ll l = 0,r = 0,sum = 0;
	ll cnt = (n+1)/2;
	while(r<cnt)
		sum+=temp[r++];
	res = sum;
	/*for (int i = 0; i < 2*n; ++i)
	{
		cout<<temp[i]<<' ';
	}
	cout<<endl;
	cout<<cnt-1<<' '<<res<<endl;*/
	for (int i = cnt; i < 2*n; ++i)
	{
		sum+=temp[i];
		sum-=temp[l++];
	//	cout<<i<<' '<<sum<<endl;
		res = max(res,sum);
	}
	cout<<res<<'\n';
	return 0;
}