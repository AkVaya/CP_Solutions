#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	long long n,sum=0;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int ans = n;
	sort(a,a+n);
	for (int i = 0; i < n; ++i)
	{
		if(sum>a[i]){
			ans--;
			continue;
		}
		sum+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}