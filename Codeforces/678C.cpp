#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,b,p,q,g,res=0,cnt;
	cin>>n>>a>>b>>p>>q;
	g = __gcd(a,b);
	cnt = (a*b)/g;
	cnt = n/cnt;
	res+=cnt*max(p,q);
	res+=(n/a-cnt)*p;
	res+=(n/b-cnt)*q;
	cout<<res<<'\n';
	return 0;
}