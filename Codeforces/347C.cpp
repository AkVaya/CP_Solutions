#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin>>n;
	int a[n],gcd=-1,mx=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(gcd==-1)
			gcd=a[i];
		else
			gcd=__gcd(a[i],gcd);
		mx=max(mx,a[i]);
	}
	mx/=gcd;
	if((mx-n)%2){
		cout<<"Alice\n";
	}
	else
		cout<<"Bob\n";
	return 0;
}