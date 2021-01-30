#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 69;
int r[nax],c[nax],n,r1[nax],c1[nax];
int main(){
	int q,a,b,x,d;
	cin>>n>>q;
	r[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>r1[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>c1[i];
	}
	int temp = 0;
	for (int i = 1; i < n; ++i)
	{
		if((r1[i]%2)!=(r1[i-1]%2))
			r[i]=++temp;
		else
			r[i] = temp;
	}
	c[0] = temp;
	for (int i = 1; i < n; ++i)
	{
		if((c1[i]%2)!=(c1[i-1]%2))
			c[i]=++temp;
		else
			c[i] = temp;
	}
	while(q--){
		cin>>a>>b>>x>>d;
		a--;
		b--;
		x--;
		d--;
		//cout<<r[a]<<' '<<c[b]<<endl<<r[b]<<' '<<c[d]<<endl;
		if(r[a]==r[x] && c[b]==c[d] && (r1[a]+c1[b])%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}


	return 0;
}