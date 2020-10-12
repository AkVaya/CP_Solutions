#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(1){
		cin>>n;
		if(!n)
			break;
		int a[n],ans=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n-1; ++j)
			{
				int ind = lower_bound(a,a+n,a[i]+a[j]+1) - a;
				if(ind==n)
					break;
				ans+=(n-ind);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}