#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin>>n;
	ll a[n],res = 0,mn = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i]>0)
			res+=a[i];
		if(a[i]%2)
			mn=min(mn,abs(a[i]));	
	}
	if(res%2)
		cout<<res<<endl;
	else{
		cout<<res-abs(mn)<<endl;
	}
	return 0;
}   